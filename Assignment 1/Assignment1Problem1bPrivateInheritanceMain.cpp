/*
Source file name: Assignment1Problem1bPrivateInheritanceMain.cpp
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This program tests the circular queue using private inheritance

The following are the functions in the program:
main() - the main function
emptyQueue() - tests if the queue is empty
*/

#include "Assignment1Problem1bPrivateInheritance.h"
#include <string>
#include <iostream>

using namespace std;

void emptyQueue(Queue* queue);

int main()
{
	Queue queue;

	emptyQueue(&queue);
	cout << "Pushing Tom onto the queue..." << endl;
	queue.push("Tom");
	cout << "Pushing Dick onto the queue..." << endl;
	queue.push("Dick");
	cout << "Pushing Harry onto the queue..." << endl;
	queue.push("Harry");
	cout << "Pushing Juliet onto the queue..." << endl;
	queue.push("Juliet");
	emptyQueue(&queue);


	cout << "The first data value in the queue is: " << queue.front() << endl;
	cout << "The last data value in the queue is: " << queue.back() << endl;

	cout << "The size of the queue is: " << queue.size() << endl;

	cout << "Popping a value..." << endl;
	queue.pop();
	cout << "The size of the queue is: " << queue.size() << endl;
	cout << "The first data value in the queue is: " << queue.front() << endl;


}

void emptyQueue(Queue* queue)
{
	if (queue->empty())
		cout << "The queue is empty" << endl;
	else
		cout << "The queue is not empty" << endl;

}