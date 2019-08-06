/*
Source file name: Assignment1Problem1aMain.cpp
Asignment number: Assignment 1 Problem 1a
Author: Shelby Simpson
Date: 10/22/2018

This program tests the functionality of the circular list

The following are the functions in the program:
main() - the main function
listEmpty() - tests if the list is empty
*/

#include "Assignment1Problem1a.h"

#include <string>
#include <iostream>
#include <cassert>

using namespace std;


//This function checks if a list is empty using the List.empty() method

void listEmpty(List list);



int main()
{  
   List staff;

   listEmpty(staff);
   cout << '\n';
   cout << "Pushing Tom onto the list..." << endl;
   staff.push_back("Tom");
   cout << "Pushing Dick onto the list..." << endl;
   staff.push_back("Dick");
   cout << "Pushing Harry onto the list..." << endl;
   staff.push_back("Harry");
   cout << "Pushing Juliet onto the list..." << endl;
   staff.push_back("Juliet");
   cout << '\n';
   listEmpty(staff);
   cout << '\n';
   // Add a value in fourth place

   Iterator pos;
   pos = staff.begin();
   pos.next();
   pos.next();
   pos.next();

   cout << "Inserting Romeo into the fourth position...\n" << endl;
   staff.insert(pos, "Romeo");

   // Remove the value in second place

   pos = staff.begin();

   cout << "Erasing the node in the first position (sorry Tom)...\n" << endl;
   staff.erase(pos);

   // Print all values

   cout << "Printing all values in the list" << endl;
   staff.print();
   cout << '\n';
   //Removing the value in the last position

   pos = staff.end();
   cout << "Erasing the node in the last position (sorry Juliet)...\n" << endl;
   staff.erase(pos);

   cout << "Printing all values in the list" << endl;
   staff.print();
   cout << '\n';

   //Traversing from the last position to the first position by pos.next()
   pos = staff.end();
   pos.next();
   cout << "This is the data in the position after the last position..." << endl;
   cout << pos.get() << endl;

   return 0;
}

void listEmpty(List list)
{
	if (list.empty())
		cout << "This list is empty" << endl;
	else
		cout << "This list is not empty" << endl;
}
