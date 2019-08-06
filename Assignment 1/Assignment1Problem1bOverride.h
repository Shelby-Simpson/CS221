/*
Source file name: Assignment1Problem1bOverride.h
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This is the header file for the circular queue using public method override

The only class in this file is the Queue class.  It publicly inherited from the List class
*/

#ifndef CIRCULAR_QUEUE_OVERRIDE_H
#define CIRCULAR_QUEUE_OVERRIDE_H

#include "Assignment1Problem1a.h"
#include <string>

using namespace std;

class Queue : public List
{
public:
	/**
	Creates an empty queue.
	*/
	Queue();
	
	/**
	Gets the data of the last and most recently added node at the back of the queue.
	@return a string containing the value of the last node in the queue
	*/
	string back();

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
	/**
	Overrides the public method "List.empty()"
	@return a boolean.  True if empty, false if not.
	*/
	bool empty();
};
#endif