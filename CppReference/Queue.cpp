#include "Queue.h"
#include <string>

Queue::Queue()
{
	
}

void Queue::AddItem(const std::string itemToAdd)
{
	items.push(itemToAdd);
}

void Queue::AddMultipleItems(const std::vector<std::string>& itemsToAdd)
{
	for (const std::string& item : itemsToAdd)
	{
		items.push(item);
	}
}

std::queue<std::string> Queue::GetAllItems() const
{
	return items;
}

std::string Queue::PeekNextItem() const
{
	return items.front();
}

std::string Queue::PeekLastItem() const
{
	return items.back();
}

void Queue::RemoveNextItem()
{
	items.pop();
}

void Queue::RemoveLastItem()
{
	std::queue<std::string> tempItems;
	int queueSize = items.size();

	for (int i = 0; i < queueSize - 1; i++)
	{
		tempItems.push(items.front());
		items.pop();
	}

	items = tempItems;
}

bool Queue::IsEmpty()
{
	return items.empty();
}

int Queue::NumItems()
{
	return items.size();
}

void Queue::PrintAllItems() const
{
	std::queue<std::string> tempItems = items;

	std::cout << "Items in queue: ";

	for (int i = 0; i < items.size(); i++)
	{
		std::cout << tempItems.front() << (i == (items.size() - 1) ? "\n" : ", ");
		tempItems.pop();
	}
}

void Queue::Demo()
{
	std::cout << "\n################################## QUEUE DEMO ##################################\n\n";

	int choice;
	
	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Add one item\n"
				  << "[2] Add multiple items\n"
				  << "[3] Look at the next item in the queue\n"
				  << "[4] Look at the last item in the queue\n"
				  << "[5] Remove the next item from the queue\n"
				  << "[6] Remove the last item from the queue\n"
				  << "[7] Check if the queue is empty\n"
				  << "[8] Get the total number of items in the queue\n"
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
				std::cout << "Enter an item you would like to add:\n";
				std::cin >> model;
				AddItem(model);
				break;
			case 2:
				do
				{
					std::cout << "Enter an item you would like to add or enter 0 if finished:\n";
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
				std::cout << "Next item in the queue: " << PeekNextItem() << "\n";
				break;
			case 4:
				std::cout << "Last item in the queue: " << PeekLastItem() << "\n";
				break;
			case 5:
				std::cout << "Removing the next item from the queue: " << PeekNextItem() << "\n";
				RemoveNextItem();
				break;
			case 6:
				std::cout << "Removing the last item from the queue: " << PeekLastItem() << "\n";
				RemoveLastItem();
				break;
			case 7:
				std::cout << "The queue is " << (IsEmpty() ? "" : "not ") << "empty\n";
				break;
			case 8:
				std::cout << "There " << (NumItems() == 1 ? ("is " + std::to_string(NumItems()) + " item") :
					("are " + std::to_string(NumItems()) + " items"))
						  << " in the queue\n";
				break;
			default:
				std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAllItems();

	} while (choice != 0);
}
