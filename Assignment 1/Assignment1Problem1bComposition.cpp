/*
Source file name: Assignment1Problem1bComposition.cpp
Assignment number: Assignment 1 Problem 1b
Author: Shelby Simpson
Date: 10/22/2018

This is the implementation file for Assignment1Problem1bComposition.h
*/

#include "Assignment1Problem1bComposition.h"

#include <string>

using namespace std;

Queue::Queue(List list)
{
	linkedList = list;
}

string Queue::back()
{
	Iterator pos = linkedList.end();
	string back = pos.get();
	return back;
}

bool Queue::empty()
{
	return linkedList.empty();
}

string Queue::front()
{
	Iterator pos = linkedList.begin();
	string front = pos.get();
	return front;
}

void Queue::pop()
{
	Iterator pos = linkedList.begin();
	linkedList.erase(pos);
	return;
}

void Queue::push(string data)
{
	linkedList.push_back(data);
}

int Queue::size()
{
	Iterator pos;
	int size = 0;
	pos = linkedList.begin();
	while (true)
	{
		if (pos.equals(linkedList.end()))
		{
			size++;
			return size;
		}
		size++;
		pos.next();
	}
}
