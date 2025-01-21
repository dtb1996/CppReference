#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Queue
{
public:
	Queue();

	/**
	* Adds a item to the end of the queue
	* @param itemToAdd The name of the item to be added
	*/
	void AddItem(const std::string itemToAdd);

	/**
	* Adds the specified items to the end of the queue
	* @param itemsToAdd The names of the items to be added
	*/
	void AddMultipleItems(const std::vector<std::string>& itemsToAdd);

	/**
	* Returns the entire queue of items
	*/
	std::queue<std::string> GetAllItems() const;

	/**
	* Returns the name of the next item
	*/
	std::string PeekNextItem() const;

	/**
	* Returns the name of the item at the end
	*/
	std::string PeekLastItem() const;

	/**
	* Removes the next item from the queue
	*/
	void RemoveNextItem();

	/**
	* Removes the last item from the queue
	*/
	void RemoveLastItem();

	/**
	* Returns true if the queue is empty, otherwise false
	*/
	bool IsEmpty();

	/**
	* Returns the total number of items in queue
	*/
	int NumItems();

	/**
	* Prints the name of each item in the queue
	*/
	void PrintAllItems() const;

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	std::queue<std::string> items;
};
