#pragma once

#include <iostream>

struct SinglyLinkedNode
{
	std::string item;
	SinglyLinkedNode* next;
};

struct DoublyLinkedNode
{
	std::string item;
	DoublyLinkedNode* previous;
	DoublyLinkedNode* next;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList();

	/**
	* Adds a node to the beginning of the list
	* @param value The value to be added
	*/
	void InsertNodeAtBeginning(const std::string value);

	/**
	* Adds a node to the end of the list
	* @param value The value to be added
	*/
	void InsertNodeAtEnd(const std::string value);

	/**
	* Removes the first node in the list
	*/
	void RemoveFirstNode();

	/**
	* Removes the last node in the list
	*/
	void RemoveLastNode();

	/**
	* Removes a node at the specified position
	* @param position The position of the node that should be removed
	*/
	void RemoveNodeAtPosition(const int position);

	/**
	* Returns the length of the list
	*/
	int GetListLength() const;

	/**
	* Returns true if the list is empty, otherwise false
	*/
	bool IsEmpty() const;

	/**
	* Removes the last node in the list
	* @param value The value to search for
	*/
	bool SearchForValue(const std::string value);

	/**
	* Prints all values in the list
	*/
	void PrintAllValues();

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	SinglyLinkedNode* singlyLinkedHead;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList();

	// TODO: Insert, Delete, and Traversal functions

private:
	DoublyLinkedNode* doublyLinkedHead;
};

