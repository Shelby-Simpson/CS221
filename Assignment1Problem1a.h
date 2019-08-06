/*
Source file name: Assignment1Problem1a.h
Assignment number: Assignment 1 Problem 1a
Author: Shelby Simpson
Date: 10/22/2018

This is the header file for the circular list

The classes in the header file include the Node class, the List class, and the Iterator class
*/

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <string>

using namespace std;

class Node
{
public:
	/**
	Constructs a node with a given data value.
	@param s the data to store in this node
	*/
	Node(string s);
private:
	string data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};

class List
{
public:
	/**
	Constructs an empty list;
	*/
	List();
	/**
	Appends an element to the list.
	@param data the value to append
	*/
	void push_back(string data);
	/**
	Inserts an element into the list.
	@param iter the position before which to insert
	@param s the value to append
	*/
	void insert(Iterator iter, string s);
	/**
	Checks if the list is empty.
	@return a boolean: true if it is empty, false if it is not
	*/
	bool empty();
	/**
	Prints all nodes in the list from first to last.
	*/
	void print();
	/**
	Removes an element from the list.
	@param iter the position to remove
	@return an iterator pointing to the element after the
	erased element
	*/
	Iterator erase(Iterator iter);
	/**
	Gets the beginning position of the list.
	@return an iterator pointing to the beginning of the list
	*/
	Iterator begin();
	/**
	Gets the past-the-end position of the list.
	@return an iterator pointing past the end of the list
	*/
	Iterator end();
private:
	Node* first;
	Node* last;
	friend class Iterator;
};

class Iterator
{
public:
	/**
	Constructs an iterator that does not point into any list.
	*/
	Iterator();
	/**
	Looks up the value at a position.
	@return the value of the node to which the iterator points
	*/
	string get() const;
	/**
	Advances the iterator to the next node.
	*/
	void next();
	/**
	Moves the iterator to the previous node.
	*/
	void previous();
	/**
	Compares two iterators
	@param b the iterator to compare with this iterator
	@return true if this iterator and b are equal
	*/
	bool equals(Iterator b) const;
private:
	Node* position;
	List* container;
	friend class List;
};

#endif