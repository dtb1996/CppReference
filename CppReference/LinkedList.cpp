#include "LinkedList.h"
#include <string>

SinglyLinkedList::SinglyLinkedList()
{

}

void SinglyLinkedList::InsertNodeAtBeginning(const std::string value)
{
	SinglyLinkedNode* newNode = new SinglyLinkedNode;
	newNode->item = value;

	// Set the next pointer to the current head
	newNode->next = singlyLinkedHead;

	// Set the new node as the list head
	singlyLinkedHead = newNode;
}

void SinglyLinkedList::InsertNodeAtEnd(const std::string value)
{
	SinglyLinkedNode* newNode = new SinglyLinkedNode;
	newNode->item = value;
	newNode->next = nullptr;

	// If the list is empty, set the new node as the head
	if (singlyLinkedHead == nullptr)
	{
		singlyLinkedHead = newNode;
	}

	// Traverse the list until the last node is found
	SinglyLinkedNode* current = singlyLinkedHead;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	// Link the new node to the current last node
	current->next = newNode;
}

void SinglyLinkedList::RemoveFirstNode()
{
	// Check if list is empty
	if (IsEmpty())
	{
		return;
	}

	// Set the head to point to the next node
	SinglyLinkedNode* temp = singlyLinkedHead;
	singlyLinkedHead = singlyLinkedHead->next;

	delete temp;
}

void SinglyLinkedList::RemoveLastNode()
{
	// Check if list is empty
	if (IsEmpty())
	{
		return;
	}

	// If list only contains one node, delete that node
	if (singlyLinkedHead->next == nullptr)
	{
		delete singlyLinkedHead;
		return;
	}

	// Find the second to last node
	SinglyLinkedNode* secondToLast = singlyLinkedHead;
	while (secondToLast->next->next != nullptr)
	{
		secondToLast = secondToLast->next;
	}

	// Delete the last node
	delete secondToLast->next;

	secondToLast->next = nullptr;
}

void SinglyLinkedList::RemoveNodeAtPosition(const int position)
{
	// Check if list is empty or an invalid position was provided
	if (IsEmpty() || position < 1)
	{
		return;
	}

	// Check if the first node needs to be removed
	if (position == 1)
	{
		SinglyLinkedNode* temp = singlyLinkedHead;
		singlyLinkedHead = singlyLinkedHead->next;
		delete temp;
		return;
	}

	// Move to the node before the position to be deleted
	SinglyLinkedNode* current = singlyLinkedHead;
	for (int i = 1; i < position - 1 && current != nullptr; i++)
	{
		current = current->next;
	}

	// Handle position that is out of range
	if (current == NULL || current->next == nullptr)
	{
		return;
	}

	// Node to be removed
	SinglyLinkedNode* temp = current->next;

	// Update current->next to point at node after the node to be deleted
	current->next = current->next->next;

	delete temp;
}

int SinglyLinkedList::GetListLength() const
{
	int count = 0;

	for (SinglyLinkedNode* current = singlyLinkedHead; current != nullptr; current = current->next)
	{
		count++;
	}

	return count;
}

bool SinglyLinkedList::IsEmpty() const
{
	return singlyLinkedHead == nullptr;
}

bool SinglyLinkedList::SearchForValue(const std::string value)
{
	SinglyLinkedNode* current = singlyLinkedHead;

	// Traverse list
	while (current != nullptr)
	{
		// Check if current node has value
		if (current->item == value)
		{
			return true;
		}

		// Set current to next node
		current = current->next;
	}

	// Value not found
	return false;
}

void SinglyLinkedList::PrintAllValues()
{
	SinglyLinkedNode* current = singlyLinkedHead;

	// Traverse list
	while (current != nullptr)
	{
		// Print the current item value
		std::cout << current->item << ((current->next != nullptr) ? ", " : "");

		// Set current to next node
		current = current->next;
	}

	std::cout << "\n";
}

void SinglyLinkedList::Demo()
{
	std::cout << "\n############################ SINGLY LINKED LIST DEMO ##################################\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Insert item at beginning of list\n"
				  << "[2] Insert item at end of list\n"
				  << "[3] Remove item at beginning of list\n"
				  << "[4] Remove item at end of list\n"
				  << "[5] Remove node at specific position\n"
				  << "[6] Check number of items in the list\n"
			      << "[7] Check if the list is empty\n"
				  << "[8] Search for an item\n"
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

		std::string item = "";
		int position = 0;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			std::cout << "Enter an item to add to the beginning of the list:\n";
			std::cin >> item;
			InsertNodeAtBeginning(item);
			break;
		case 2:
			std::cout << "Enter an item to add to the end of the list:\n";
			std::cin >> item;
			InsertNodeAtEnd(item);
			break;
		case 3:
			std::cout << "Removing the first item from the list:\n";
			RemoveFirstNode();
			break;
		case 4:
			std::cout << "Removing the last item from the list:\n";
			RemoveLastNode();
			break;
		case 5:
			std::cout << "Enter an item position to remove from the list:\n";
			while (true) {
				if (std::cin >> position) {
					break;
				}
				else {
					std::cout << "Invalid input. Please enter an integer.\n";
					std::cin.clear(); // Clear the error state
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the remaining input
				}
			}
			RemoveNodeAtPosition(position);
			break;
		case 6:
			std::cout << "There " << (GetListLength() == 1 ? ("is " + std::to_string(GetListLength()) + " item") :
															 ("are " + std::to_string(GetListLength()) + " items"))
								  << " in the queue\n";
			break;
		case 7:
			std::cout << "The list is " << (IsEmpty() ? "" : "not") << " empty\n";
			break;
		case 8:
			std::cout << "Enter an item to search for:\n";
			std::cin >> item;
			std::cout << "The item was " << (SearchForValue(item) ? "" : "not ") << "found\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAllValues();

	} while (choice != 0);
}

DoublyLinkedList::DoublyLinkedList()
{

}

void DoublyLinkedList::InsertNodeAtBeginning(const std::string value)
{
	DoublyLinkedNode* newNode = new DoublyLinkedNode;
	newNode->item = value;
	newNode->previous = nullptr;

	// Set the next pointer to the current head
	newNode->next = doublyLinkedHead;

	// Set the head->previous to the new node
	if (doublyLinkedHead != nullptr)
	{
		doublyLinkedHead->previous = newNode;
	}

	// Set the new node as the list head
	doublyLinkedHead = newNode;
}

void DoublyLinkedList::InsertNodeAtEnd(const std::string value)
{
	DoublyLinkedNode* newNode = new DoublyLinkedNode;
	newNode->item = value;
	newNode->previous = nullptr;
	newNode->next = nullptr;

	// If the list is empty, set the new node as the head
	if (doublyLinkedHead == nullptr)
	{
		doublyLinkedHead = newNode;
		return;
	}

	// Traverse the list until the last node is found
	DoublyLinkedNode* current = doublyLinkedHead;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	// Link the new node to the current last node
	current->next = newNode;

	// Set the previous of the new node to the last node
	newNode->previous = current;
}

void DoublyLinkedList::RemoveFirstNode()
{
	// Check if list is empty
	if (IsEmpty())
	{
		return;
	}

	// Set the head to point to the next node
	DoublyLinkedNode* temp = doublyLinkedHead;
	doublyLinkedHead = doublyLinkedHead->next;

	// Set previous of the new head
	if (doublyLinkedHead != nullptr)
	{
		doublyLinkedHead->previous = nullptr;
	}

	delete temp;
}

void DoublyLinkedList::RemoveLastNode()
{
	// Check if list is empty
	if (IsEmpty())
	{
		return;
	}

	// If list only contains one node, delete that node
	if (doublyLinkedHead->next == nullptr)
	{
		delete doublyLinkedHead;
		return;
	}

	// Find the last node
	DoublyLinkedNode* current = doublyLinkedHead;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	// Update the previous node's next pointer
	current->previous->next = nullptr;

	// Delete the last node
	delete current;
}

void DoublyLinkedList::RemoveNodeAtPosition(const int position)
{
	// Check if list is empty or an invalid position was provided
	if (IsEmpty() || position < 1)
	{
		return;
	}

	// Move to the node at the position to be deleted
	DoublyLinkedNode* current = doublyLinkedHead;
	for (int i = 1; current != nullptr && i < position; ++i)
	{
		current = current->next;
	}

	// Handle position that is out of range
	if (current == NULL)
	{
		return;
	}

	// Update the previous node's next pointer
	if (current->previous != nullptr)
	{
		current->previous->next = current->next;
	}

	// Update the next node's previous pointer
	if (current->next != nullptr)
	{
		current->next->previous = current->previous;
	}

	// Check if the node to be deleted is the list head
	if (doublyLinkedHead == current)
	{
		doublyLinkedHead = current->next;
	}

	delete current;
}

int DoublyLinkedList::GetListLength() const
{
	int count = 0;

	for (DoublyLinkedNode* current = doublyLinkedHead; current != nullptr; current = current->next)
	{
		count++;
	}

	return count;
}

bool DoublyLinkedList::IsEmpty() const
{
	return doublyLinkedHead == nullptr;
}

bool DoublyLinkedList::SearchForValue(const std::string value)
{
	DoublyLinkedNode* current = doublyLinkedHead;

	// Traverse list
	while (current != nullptr)
	{
		// Check if current node has value
		if (current->item == value)
		{
			return true;
		}

		// Set current to next node
		current = current->next;
	}

	// Value not found
	return false;
}

void DoublyLinkedList::PrintAllValues()
{
	DoublyLinkedNode* current = doublyLinkedHead;

	// Traverse list
	while (current != nullptr)
	{
		// Print the current item value
		std::cout << current->item << ((current->next != nullptr) ? ", " : "");

		// Set current to next node
		current = current->next;
	}

	std::cout << "\n";
}

void DoublyLinkedList::Demo()
{
	std::cout << "\n############################ DOUBLY LINKED LIST DEMO ##################################\n\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Insert item at beginning of list\n"
			<< "[2] Insert item at end of list\n"
			<< "[3] Remove item at beginning of list\n"
			<< "[4] Remove item at end of list\n"
			<< "[5] Remove node at specific position\n"
			<< "[6] Check number of items in the list\n"
			<< "[7] Check if the list is empty\n"
			<< "[8] Search for an item\n"
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

		std::string item = "";
		int position = 0;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			std::cout << "Enter an item to add to the beginning of the list:\n";
			std::cin >> item;
			InsertNodeAtBeginning(item);
			break;
		case 2:
			std::cout << "Enter an item to add to the end of the list:\n";
			std::cin >> item;
			InsertNodeAtEnd(item);
			break;
		case 3:
			std::cout << "Removing the first item from the list:\n";
			RemoveFirstNode();
			break;
		case 4:
			std::cout << "Removing the last item from the list:\n";
			RemoveLastNode();
			break;
		case 5:
			std::cout << "Enter an item position to remove from the list:\n";
			while (true) {
				if (std::cin >> position) {
					break;
				}
				else {
					std::cout << "Invalid input. Please enter an integer.\n";
					std::cin.clear(); // Clear the error state
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the remaining input
				}
			}
			RemoveNodeAtPosition(position);
			break;
		case 6:
			std::cout << "There " << (GetListLength() == 1 ? ("is " + std::to_string(GetListLength()) + " item") :
				("are " + std::to_string(GetListLength()) + " items"))
				<< " in the queue\n";
			break;
		case 7:
			std::cout << "The list is " << (IsEmpty() ? "" : "not") << " empty\n";
			break;
		case 8:
			std::cout << "Enter an item to search for:\n";
			std::cin >> item;
			std::cout << "The item was " << (SearchForValue(item) ? "" : "not ") << "found\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAllValues();

	} while (choice != 0);
}
