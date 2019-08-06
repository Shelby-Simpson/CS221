/*
Source file name: Assignment1Problem3.cpp
Assignment number: Assignment 1 Problem 3
Author: Shelby Simpson
Date: 10/22/2018

Theis  program is an implementation of E.W. Dijkstra's algorithm
for evaluating infix arithmetic expressions.

The following are the major functions of the program:
main() - the main function
expressionEvaluator(string str) - this implements Dijkstra's algorithm
applyOperator(stack<char>* charStack, stack<int>* intStack) - this evalutes all expressions in between
parentheses in the original expression or evaluates the entire expression when the end of the 
input string is reached.
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/*
This function implements E.W. Dijkstra's algorithm on the user-inputed expression.
@param a string containing the expression
@return a double representing the result of the expression evaluation
*/
double expressionEvaluator(string str);

/*
This function applies operators to operands if a ")" is found in the input or 
the end of the expression is reached.
@param a pointer to the operator stack
@param a pointer to the operand stack
*/
void applyOperator(stack<char>* charStack, stack<double>* doubleStack);

int main()
{
	string input;
	cout << "This program evaluates your arithmetic expressions." << endl;
	while (true)
	{
		cout << "All operands must be integers." << endl;
		cout << "DO NOT multiply operands without the '*' operator."
			<< "E.g. 1(2+1) is NOT ALLOWED.  Please replace it with 1*(2+1). (Ctrl-C to quit)" << endl;
		getline(cin, input);
		//We test if the input is blank or only consists of spaces
		if (input.empty() || all_of(input.begin(), input.end(), isspace))
		{
			cout << "You didn't input an expression.  Press enter and then please try again (Ctrl-C to quit)" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		try 
		{
			expressionEvaluator(input);
		}
		catch (const char* str)
		{
			cout << "You did not enter a correct expression.  Press enter and then please try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
			
		}
		double result = expressionEvaluator(input);
		cout << "The result of your expression is: " << result << endl;
		break;
	}
}

double expressionEvaluator(string str)
{
	//Initialize some variables
	stack<double> operandStack;
	stack<char> operatorStack;
	string strTemp;
	double doubleTemp1;
	double doubleTemp2;
	string::iterator checker;
	checker = str.end();
	checker--;
	bool requiresInteger = true;
	bool isLeftParenthesis = false;

	//We check if the first and last chars in input are integers or spaces
	if ((!isdigit(*str.begin()) && *str.begin() != ' ') || (!isdigit(*checker) && *checker != ' ') && *checker != ')')
		throw "First or last char in expression is incorrect.";

	//E.W. Dijkstra's algorithm
	for (string::iterator pos = str.begin(); pos != str.end(); pos++)
	{
		if (*pos == ' ') //pos is in between an operand, an operator, or a paranthesis
			continue;
		else
		{
			if (!isdigit(*pos))
			{
				//We check if an integer is required at this position in a valid expression
				if (requiresInteger)
					throw "An integer is required at this position in a valid expression.";
				else
				{
					//We check if all nonintegers values are operators or parentheses
					if (*pos != '(' && *pos != ')' && *pos != '+' && *pos != '-' && *pos != '*' && *pos != '/')
						throw "Not all characters in expression are integers, operators, or parentheses";
					else
					{
						if (!strTemp.empty())
						{
							operandStack.push(stoi(strTemp, nullptr, 10)); //pushes the operand onto the operand stack
							strTemp.clear();
						}
						if (operatorStack.empty()) //operator stack is empty
						{
							operatorStack.push(*pos);
							continue;
						}
						else
						{
							if (*pos == '+' || *pos == '-') //'+' or '-' priority cannot be greater than the priority of the operator at top of stack
							{
								if (*(pos++) != '(')
									requiresInteger = true;
								pos--;
								applyOperator(&operatorStack, &operandStack);
								operatorStack.push(*pos);
							}
							else if (*pos == '*' || *pos == '/')
							{
								if (*(pos++) != '(')
									requiresInteger = true;
								pos--;
								if (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '(')
									operatorStack.push(*pos);
								else
								{
									doubleTemp2 = operandStack.top();
									operandStack.pop();
									doubleTemp1 = operandStack.top();
									operandStack.pop();
									operatorStack.pop();
									switch (*pos)
									{
									case '*':
										operandStack.push(doubleTemp1 * doubleTemp2);
										break;
									case '/':
										operandStack.push(doubleTemp1 / doubleTemp2);
										break;
									}
									operatorStack.push(*pos);
								}
							}
							else if (*pos == '(')
							{
								isLeftParenthesis = true;
								requiresInteger = true;
								operatorStack.push(*pos);
							}
							else if (*pos == ')')
							{
								//We check if a left parenthesis was inputting before a right parenthesis
								if (isLeftParenthesis)
									applyOperator(&operatorStack, &operandStack);
								else
									throw "A right parenthesis was placed before a left parenthesis";
							}
						}
						continue;
					}
				}
			}
			requiresInteger = false;
			strTemp.append(1, *pos); //An integer can have multiple digits
			continue;
		}
	}
	if (!strTemp.empty())
		operandStack.push(stoi(strTemp, nullptr, 10)); //This pushes the last integer onto the operand stack
	applyOperator(&operatorStack, &operandStack);
	return operandStack.top();
}

void applyOperator(stack<char>* charStack, stack<double>* doubleStack)
{
	//Initialize some variables
	char charTemp;
	double doubleTemp1, doubleTemp2;

	//Continue to pop off operators, evaluate operands, and push the results until '(' is popped or operator stack is empty
	while (!charStack->empty())
	{
		doubleTemp2 = doubleStack->top();
		doubleStack->pop();
		doubleTemp1 = doubleStack->top();
		doubleStack->pop();
		charTemp = charStack->top();
		charStack->pop();
		switch (charTemp)
		{
		case '+':
			doubleStack->push(doubleTemp1 + doubleTemp2);
			break;
		case '-':
			doubleStack->push(doubleTemp1 - doubleTemp2);
			break;
		case '*':
			doubleStack->push(doubleTemp1 * doubleTemp2);
			break;
		case '/':
			doubleStack->push(doubleTemp1 / doubleTemp2);
			break;
		case '(':
			doubleStack->push(doubleTemp1);
			doubleStack->push(doubleTemp2);
			return;
		case ')':
			applyOperator(charStack, doubleStack);
			break;
		}
	}
	return;
}