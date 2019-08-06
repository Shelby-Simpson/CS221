/*
Source file name: Assignment1Problem1a.cpp
Assignment number: Assignment 1 Problem 1a
Author: Shelby Simpson
Date: 10/22/2018

This is the implementation file for Assignment1Problem1a.h
*/

#include "Assignment1Problem1a.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

Node::Node(string s)
{
	data = s;
	previous = NULL;
	next = NULL;
}


List::List()
{
	first = NULL;
	last = NULL;
}

void List::push_back(string data)
{
	Node* new_node = new Node(data);
	if (first == NULL) // List is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		last->next = new_node;
		first->previous = new_node;
	}
	new_node->previous = last;
	new_node->next = first;
	last = new_node;
}

void List::insert(Iterator iter, string s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);
	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;
	if (before == last) // Insert at beginning
		first = new_node;
	before->next = new_node;
}

bool List::empty()
{
	if (first == NULL)
		return true;
	else
		return false;
}

void List::print()
{
	Iterator iter;
	iter.position = first;
	while (true)
	{
		if (iter.position == last)
		{
			cout << "Data: " << iter.position->data << endl;
			return;
		}
		cout << "Data: " << iter.position->data << endl;
		iter.next();
	}
}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	before->next = after;
	after->previous = before;
	if (remove == first)
		first = after;
	if (remove == last)
		last = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = last;
	iter.container = this;
	return iter;
}

Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

string Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}