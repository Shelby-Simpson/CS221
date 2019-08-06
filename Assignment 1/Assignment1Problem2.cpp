/*
Source file name: Assignment1Problem2.cpp
Assignment number: Assignment 1 Problem 2
Author: Shelby Simpson
Date: 10/22/2018

This program implements both the merge sort algorithm and the insertion sort algorithm
to alphabetically sort the nodes of am STL list<string>.  The insertion sorting is an
additional feature of the program.

The following are the major functions of the program:
main() - the main function
stlListMergeSort(list<string> listObject) - sorts the list with the merge sort algorithm
stlListInsertionSort(list<string> listObject) - sorts the list with the insertion sort algorithm
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
This function sorts using the merge sort algorithm
@param an STL list object
@return an STL list object
*/
list<string> stlListMergeSort(list<string> listObject);

/*
***This is an additional feature of the program***
This function sorts using the insertion sort algoirthm
Elements in the sorted list don't need to be shifted every time a new element is inserted
@param an STL list object
@return an STL list object
*/
list<string> stlListInsertionSort(list<string> listObject);

int main()
{
	//Creates the list and pushes values onto it
	list<string> stringList;
	stringList.push_back("Tom");
	stringList.push_back("Dick");
	stringList.push_back("Harry");
	stringList.push_back("Romeo");
	stringList.push_back("Juliet");

	//Inserts "John" at position 4
	list<string>::iterator pos;
	pos = stringList.begin();
	pos++;
	pos++;
	pos++;
	stringList.insert(pos, "John");

	//Prints all values in the list
	cout << "This is the unsorted list" << endl;
	pos = stringList.begin();
	while (pos != stringList.end())
	{
		cout << *pos << endl;
		pos++;
	}
	cout << '\n';

	//Sorts the list using merge sort
	list<string> stringListMergeSorted = stlListMergeSort(stringList);

	//Prints all values of the list sorted with merge sort
	cout << "This list was sorted with merge sort" << endl;
	pos = stringListMergeSorted.begin();	
	while (pos != stringListMergeSorted.end())
	{
		cout << *pos << endl;
		pos++;
	}
	cout << '\n';

	//Prints all values in the unsorted list again
	cout << "This is the unsorted list again" << endl;
	pos = stringList.begin();
	while (pos != stringList.end())
	{
		cout << *pos << endl;
		pos++;
	}
	cout << '\n';

	//Sorts the list using insertion sort
	list<string> stringListInsertionSorted = stlListMergeSort(stringList);

	//Prints all values of the list sorted with insertion sort
	cout << "This list was sorted with insertion sort" << endl;
	pos = stringListInsertionSorted.begin();
	while (pos != stringListInsertionSorted.end())
	{
		cout << *pos << endl;
		pos++;
	}
}

list<string> stlListMergeSort(list<string> listObject)
{
	//Base case if listObject contains 0 or 1 nodes
	if (listObject.size() <= 1)
		return listObject;

	//Initialize several variables
	list<string>* list1 = new list < string > ;
	list<string>* list2 = new list < string > ;
	list<string>* returnList = new list < string >;
	list<string>::iterator pos;
	pos = listObject.begin();
	int size = listObject.size();

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			list1->push_back(*pos);
		else
			list2->push_back(*pos);
		pos++;
	}

	//Call stlListMergeSort on list1 and list2
	*list1 = stlListMergeSort(*list1);
	*list2 = stlListMergeSort(*list2);

	//Initialize iterators for each list we will be comparing
	pos = list1->begin();
	list<string>::iterator pos2;
	pos2 = list2->begin();

	//Compare each list pushing the smaller value onto the list we will return
	while (pos != list1->end() && pos2 != list2->end())
	{
		if (*pos < *pos2)
		{
			returnList->push_back(*pos);
			pos++;
		}
		else
		{
			returnList->push_back(*pos2);
			pos2++;
		}
	}
	if (pos == list1->end())
	{
		while (pos2 != list2->end())
		{
			returnList->push_back(*pos2);
			pos2++;
		}
	}
	else
	{
		while (pos != list1->end())
		{
			returnList->push_back(*pos);
			pos++;
		}
	}

	//return the output of this merge sort call
	return *returnList;
}

list<string> stlListInsertionSort(list<string> listObject)
{
	//Initialize some variables
	list<string>::iterator pos;
	pos = listObject.begin();
	list<string>::iterator pos2;
	
	//The actual insertion sort algorithm
	while (pos != listObject.end())
	{
		if (pos == listObject.begin())
			continue;
		else
		{
			pos2 = listObject.begin();
			while (pos2 != pos)
			{
				if (*pos > *pos2)
				{
					pos2++;
				}
			}
			listObject.insert(pos2, *pos);
			listObject.erase(pos);
		}
		pos++;
	}
	
	//Return the output of the insertion sort call
	return listObject;
}