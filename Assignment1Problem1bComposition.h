/*
Source file name: Assigment1Problem1Composition.h
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This is the header file for the composition program

The class in this header is the Queue class
*/

#ifndef CIRCULAR_QUEUE_COMPOSITION_H
#define CIRCULAR_QUEUE_COMPOSITION_H

#include "Assignment1Problem1a.h"
#include <string>

using namespace std;

class Queue
{
public:
	/**
	Constructs an empty queue.
	*/
	Queue(List list);

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
	Adds an element to the back of the queue.
	@param data being added at the back of the queue
	*/
	void push(string data);

	/**
	@return an integer representing the number of elements in the queue.
	*/
	int size();

private:
	List linkedList;
};
#endif
