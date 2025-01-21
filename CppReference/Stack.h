#pragma once

#include <iostream>
#include <stack>
#include <vector>

class Stack
{
public:
	Stack();

	/**
	* Adds a item to stack
	* @param itemToAdd The name of the item to be added
	*/
	void AddItem(const std::string itemToAdd);

	/**
	* Adds the specified items to the stack
	* @param itemsToAdd The names of the items to be added
	*/
	void AddItems(const std::vector<std::string>& itemsToAdd);

	/**
	* Returns the entire stack of items
	*/
	std::stack<std::string> GetAllItems() const;

	/**
	* Returns the name of the next item at the top of the stack
	*/
	std::string PeekNextItem() const;

	/**
	* Changes the item at the top of the stack
	*/
	std::string ChangeNextItem(const std::string newItem);

	/**
	* Removes the next item from the top of the stack
	*/
	void RemoveNextItem();

	/**
	* Returns true if the stack is empty, otherwise false
	*/
	bool IsEmpty();

	/**
	* Returns the total number of items in the stack
	*/
	int NumItems();

	/**
	* Prints the name of each item in the stack
	*/
	void PrintAllItems() const;

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	std::stack<std::string> items;
};

