#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Queue
{
public:
	Queue();

	/**
	* Adds a car to the end of the queue
	* @param car The name of the car to be added
	*/
	void AddCar(const std::string newCar);

	/**
	* Adds the specified cars to the end of the queue
	* @param newCars The names of the cars to be added
	*/
	void AddCars(const std::vector<std::string>& newCars);

	/**
	* Returns the entire queue of cars
	*/
	std::queue<std::string> GetAllCars() const;

	/**
	* Returns the name of the next car
	*/
	std::string PeekNextCar() const;

	/**
	* Returns the name of the car at the end
	*/
	std::string PeekLastCar() const;

	/**
	* Removes the next car from the queue
	*/
	void RemoveNextCar();

	/**
	* Returns the last car from the queue
	*/
	void RemoveLastCar();

	/**
	* Returns true if the queue is empty, otherwise false
	*/
	bool IsEmpty();

	/**
	* Returns the total number of cars in queue
	*/
	int NumCars();

	/**
	* Prints the name of each car in the queue
	*/
	void PrintAllCars() const;

	/**
	* Runs a basic demo of the class functions
	*/
	void Demo();

private:
	std::queue<std::string> cars;


};
