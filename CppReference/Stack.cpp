#include "Stack.h"
#include <string>

Stack::Stack()
{

}

void Stack::AddCar(const std::string newCar)
{
	cars.push(newCar);
}

void Stack::AddCars(const std::vector<std::string>& newCars)
{
	for (const std::string& newCar : newCars)
	{
		cars.push(newCar);
	}
}

std::stack<std::string> Stack::GetAllCars() const
{
	return std::stack<std::string>();
}

std::string Stack::PeekNextCar() const
{
	return cars.top();
}

std::string Stack::ChangeNextCar(const std::string newCar)
{
	return cars.top() = newCar;
}

void Stack::RemoveNextCar()
{
	cars.pop();
}

bool Stack::IsEmpty()
{
	return cars.empty();
}

int Stack::NumCars()
{
	return cars.size();
}

void Stack::PrintAllCars() const
{
	std::stack<std::string> tempCars = cars;

	std::cout << "Cars in stack: ";

	for (int i = 0; i < cars.size(); i++)
	{
		std::cout << tempCars.top() << (i == (cars.size() - 1) ? "\n" : ", ");
		tempCars.pop();
	}
}

void Stack::Demo()
{
	std::cout << "\n################################## STACK DEMO ##################################\n\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Add one car\n"
				  << "[2] Add multiple cars\n"
				  << "[3] Look at the next car in the stack\n"
				  << "[4] Change the next car in the stack\n"
				  << "[5] Remove the next car from the stack\n"
				  << "[6] Check if the stack is empty\n"
				  << "[7] Get the total number of cars in the stack\n"
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
		case 0:
			break;
		case 1:
			std::cout << "Enter a model name for the car you would like to add:\n";
			std::cin >> model;
			AddCar(model);
			break;
		case 2:
			do
			{
				std::cout << "Enter a model name for the car you would like to add or enter 0 if finished:\n";
				if (model != "0")
				{
					std::cin >> model;
					AddCar(model);

					std::cout << "\n";
					PrintAllCars();
					std::cout << "\n";
				}
			} while (model != "0");
			break;
		case 3:
			std::cout << "Next car in the stack: " << PeekNextCar() << "\n";
			break;
		case 4:
			std::cout << "Enter a new model name to replace the next car in the stack:\n";
			std::cin >> model;
			ChangeNextCar(model);
			break;
		case 5:
			std::cout << "Removing the next car from the stack: " << PeekNextCar() << "\n";
			RemoveNextCar();
			break;
		case 6:
			std::cout << "The stack is " << (IsEmpty() ? "" : "not") << " empty\n";
			break;
		case 7:
			std::cout << "There " << (NumCars() == 1 ? ("is "  + std::to_string(NumCars()) + " car") :
										               ("are " + std::to_string(NumCars()) + " cars")) 
					  << " in the stack\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAllCars();

	} while (choice != 0);

}
