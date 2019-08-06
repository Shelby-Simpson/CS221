/*
Source file name: Assignment1Problem1bPrivateInheritance.cpp
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This is the implementation file for Assignment1Problem1bPrivateInheritance.h
*/

#include "Assignment1Problem1a.h"
#include "Assignment1Problem1bPrivateInheritance.h"

#include <string>

using namespace std;

Queue::Queue() : List()
{ }

string Queue::back()
{
	Iterator pos = this->end();
	string back = pos.get();
	return back;
}

bool Queue::empty()
{
	return this->List::empty();
}

string Queue::front()
{
	Iterator pos = this->begin();
	string front = pos.get();
	return front;
}

void Queue::pop()
{
	Iterator pos = this->begin();
	this->erase(pos);
	return;
}

void Queue::push(string data)
{
	this->push_back(data);
}

int Queue::size()
{
	Iterator pos;
	int size = 0;
	pos = this->begin();
	while (true)
	{
		if (pos.equals(this->end()))
		{
			size++;
			return size;
		}
		size++;
		pos.next();
	}
}
