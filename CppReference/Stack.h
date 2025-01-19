#pragma once

#include <iostream>
#include <stack>
#include <vector>

class Stack
{
public:
	Stack();

	/**
	* Adds a car to stack
	* @param car The name of the car to be added
	*/
	void AddCar(const std::string newCar);

	/**
	* Adds the specified cars to the stack
	* @param newCars The names of the cars to be added
	*/
	void AddCars(const std::vector<std::string>& newCars);

	/**
	* Returns the entire stack of cars
	*/
	std::stack<std::string> GetAllCars() const;

	/**
	* Returns the name of the next car at the top of the stack
	*/
	std::string PeekNextCar() const;

	/**
	* Changes the car at the top of the stack
	*/
	std::string ChangeNextCar(const std::string newCar);

	/**
	* Removes the next car from the top of the stack
	*/
	void RemoveNextCar();

	/**
	* Returns true if the stack is empty, otherwise false
	*/
	bool IsEmpty();

	/**
	* Returns the total number of cars in the stack
	*/
	int NumCars();

	/**
	* Prints the name of each car in the stack
	*/
	void PrintAllCars() const;

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	std::stack<std::string> cars;
};

