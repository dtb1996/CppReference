#include "Stack.h"
#include <string>

Stack::Stack()
{

}

void Stack::AddItem(const std::string itemToAdd)
{
	items.push(itemToAdd);
}

void Stack::AddItems(const std::vector<std::string>& itemsToAdd)
{
	for (const std::string& item : itemsToAdd)
	{
		items.push(item);
	}
}

std::stack<std::string> Stack::GetAllItems() const
{
	return std::stack<std::string>();
}

std::string Stack::PeekNextItem() const
{
	return items.top();
}

std::string Stack::ChangeNextItem(const std::string newItem)
{
	return items.top() = newItem;
}

void Stack::RemoveNextItem()
{
	items.pop();
}

bool Stack::IsEmpty()
{
	return items.empty();
}

int Stack::NumItems()
{
	return items.size();
}

void Stack::PrintAllItems() const
{
	std::stack<std::string> tempItems = items;

	std::cout << "Items in stack: ";

	for (int i = 0; i < items.size(); i++)
	{
		std::cout << tempItems.top() << (i == (items.size() - 1) ? "\n" : ", ");
		tempItems.pop();
	}
}

void Stack::Demo()
{
	std::cout << "\n################################## STACK DEMO ##################################\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Add one item\n"
				  << "[2] Add multiple items\n"
				  << "[3] Look at the next item in the stack\n"
				  << "[4] Change the next item in the stack\n"
				  << "[5] Remove the next item from the stack\n"
				  << "[6] Check if the stack is empty\n"
				  << "[7] Get the total number of items in the stack\n"
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
			std::cout << "Enter a model name for the item you would like to add:\n";
			std::cin >> model;
			AddItem(model);
			break;
		case 2:
			do
			{
				std::cout << "Enter a model name for the item you would like to add or enter 0 if finished:\n";
				std::cin >> model;
				if (model != "0")
				{
					AddItem(model);

					std::cout << "\n";
					PrintAllItems();
					std::cout << "\n";
				}
			} while (model != "0");
			break;
		case 3:
			std::cout << "Next item in the stack: " << PeekNextItem() << "\n";
			break;
		case 4:
			std::cout << "Enter a new model name to replace the next item in the stack:\n";
			std::cin >> model;
			ChangeNextItem(model);
			break;
		case 5:
			std::cout << "Removing the next item from the stack: " << PeekNextItem() << "\n";
			RemoveNextItem();
			break;
		case 6:
			std::cout << "The stack is " << (IsEmpty() ? "" : "not ") << "empty\n";
			break;
		case 7:
			std::cout << "There " << (NumItems() == 1 ? ("is " + std::to_string(NumItems()) + " item") :
				("are " + std::to_string(NumItems()) + " items"))
					  << " in the stack\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAllItems();

	} while (choice != 0);

}
