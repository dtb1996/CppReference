#include "Queue.h"

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

void Queue::Demo()
{
	std::cout << "\n################################## QUEUE DEMO ##################################\n\n";

	int choice;
	
	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Add one car\n"
				  << "[2] Add multiple cars\n"
				  << "[3] Look at the next car in the queue\n"
				  << "[4] Look at the last car in the queue\n"
				  << "[5] Remove the next car from the queue\n"
				  << "[6] Remove the last car from the queue\n"
				  << "[7] Check if the queue is empty\n"
				  << "[8] Get the total number of cars in the queue\n"
				  << "[0] Quit\n";

		while (true) {
			if (std::cin >> choice) {
				break;
			}
			else {
				std::cout << "Invalid input. Please enter an integer.\n";
				std::cin.clear(); // Clear the error state
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the remaining input
			}
		}

		std::cout << "\n";

		std::string model = "";

		switch (choice)
		{
			case 1:
				std::cout << "Enter a model name for the car you would like to add:\n";
				std::cin >> model;
				cars.push(model);
				break;
			case 2:
				do
				{
					std::cout << "Enter a model name for the car you would like to add or enter 0 if finished:\n";
					if (model != "0")
					{
						std::cin >> model;
						cars.push(model);

						std::cout << "\n";
						this->PrintAllCars();
						std::cout << "\n";
					}
				} while (model != "0");
				break;
			default:
				std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		this->PrintAllCars();

	} while (choice != 0);
}
