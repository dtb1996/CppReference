#pragma once

#include <iostream>
#include <vector>

class AdjacencyMatrix
{
public:
	AdjacencyMatrix();
};

class AdjacencyList
{
public:
	AdjacencyList();

	/**
	* Adds the specified edge to the adjacency list
	* @param source The source vertex
	* @param destination The destination vertex
	*/
	void AddEdge(const int source, const int destination);

	/**
	* Checks if the specified vertex exists in the list
	* @param vertex The vertex to search for
	*/
	bool HasVertex(const int vertex);

	/**
	* Clears the adjacency list
	*/
	void ClearAdjacencyList();

	/**
	* Prints the adjacency list
	*/
	void PrintAdjacencyList() const;

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	std::vector<std::vector<int>> adjacencyList;
};

