#pragma once

#include <iostream>

struct Node
{
	std::string item;
	Node* left;
	Node* right;

	Node(std::string value) : item(value), left(nullptr), right(nullptr) {};
};

class BinaryTree
{
public:
	BinaryTree() : root(nullptr) {}

	/**
	* Inserts a node in the tree
	* @param value The value to be added
	*/
	void InsertNode(const std::string value);

	/**
	* Deletes a node from the tree
	* @param value The value to be deleted
	*/
	void DeleteNode(const std::string value);

	/**
	* Searches for a node
	* @param value The value to search for
	*/
	bool Search(const std::string value);

	/**
	* Performs pre-order traversal
	*/
	void PreOrderTraversal();

	/**
	* Performs in-order traversal
	*/
	void InOrderTraversal();

	/**
	* Performs post-order traversal
	*/
	void PostOrderTraversal();

	/**
	* Performs level-order traversal
	*/
	void LevelOrderTraversal();

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	Node* root;

	Node* DeleteRecursive(Node* current, const std::string value);

	Node* FindMinValueNode(Node* node);

	bool SearchRecursive(Node* current, const std::string value);

	void PreOrderRecursive(Node* node);

	void InOrderRecursive(Node* node);

	void PostOrderRecursive(Node* node);
};