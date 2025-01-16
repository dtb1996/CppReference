#include "Queue.h"

#define DEMO_CARS {"Volvo", "BMW", "Ford", "Mazda"}

Queue::Queue()
{
	
}

void Queue::AddCar(const std::string newCar)
{
	cars.push(newCar);
}

void Queue::AddCars(const std::vector<std::string>& newCars)
{
	for (const std::string& newCar : newCars)
	{
		cars.push(newCar);
	}
}

std::queue<std::string> Queue::GetAllCars() const
{
	return cars;
}

std::string Queue::PeekNextCar() const
{
	return cars.front();
}

std::string Queue::PeekLastCar() const
{
	return cars.back();
}

void Queue::RemoveNextCar()
{
	cars.pop();
}

void Queue::RemoveLastCar()
{
	std::queue<std::string> tempCars;
	int queueSize = cars.size();

	for (int i = 0; i < queueSize - 1; i++)
	{
		tempCars.push(cars.front());
		cars.pop();
	}

	cars = tempCars;
}

bool Queue::IsEmpty()
{
	return cars.empty();
}

int Queue::NumCars()
{
	return cars.size();
}

void Queue::PrintAllCars() const
{
	std::queue<std::string> tempCars = cars;

	std::cout << "Cars in queue: ";

	for (int i = 0; i < cars.size(); i++)
	{
		std::cout << tempCars.front() << (i == (cars.size() - 1) ? "\n" : ", ");
		tempCars.pop();
	}
}

void Queue::AddDemoCars()
{
	std::string demoCars[4] = DEMO_CARS;

	for (const auto& car : demoCars)
	{
		cars.push(car);
	}
}

void Queue::Demo()
{
	std::cout << "################################## Running Queue Demo ##################################\n\n";

	std::cout << "Adding demo cars:\n";
	this->AddDemoCars();
	this->PrintAllCars();

	std::cout << "Adding one car:\n";
	this->AddCar("Subaru");
	this->PrintAllCars();

	std::cout << "Adding multiple cars:\n";
	std::vector<std::string> newCars = { "Toyota", "Nissan", "Jeep" };
	this->AddCars(newCars);
	this->PrintAllCars();

	std::cout << "Remove next car:\n";
	this->RemoveNextCar();
	this->PrintAllCars();

	std::cout << "Remove last car:\n";
	this->RemoveLastCar();
	this->PrintAllCars();

	std::cout << "\n";
}
