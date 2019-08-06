/*
Source file name: Assignment1Problem1bPrivateInheritance.h
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This is the header file for the circular list using private inheritance

The class in this file is the Queue class
*/

#ifndef CIRCULAR_QUEUE_PRIVATE_INHERITANCE_H
#define CIRCULAR_QUEUE_PRIVATE_INHERITANCE_H

#include "Assignment1Problem1a.h"
#include <string>

using namespace std;

class Queue : List
{
public:
	/**
	Constructs an empty queue.
	*/
	Queue();

	/**
	Gets the data of the last and most recently added node at the back of the queue.
	@return a string containing the value of the last node in the queue
	*/
	string back();

	/**
	Tests if the queue is empty.
	@return a boolean.  True if empty, false if not.
	*/
	bool empty();

	/**
	Gets the data of the first element at the front of the queue.
	@return a string containing the data of the first node in the queue
	*/
	string front();

	/**
	Removes an element from the front of the queue.
	*/
	void pop();

	/**
	Pushes an element onto the queue.
	@param the value of the data as a string for the pushed element
	*/
	void push(string data);

	/**
	@return an integer representing the number of elements in the queue.
	*/
	int size();

private:
};
#endif
