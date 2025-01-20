#include "LinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	singlyLinkedHead->item = "";
	singlyLinkedHead->next = nullptr;
}

void SinglyLinkedList::InsertNodeAtBeginning(const std::string value)
{
	SinglyLinkedNode* newNode = new SinglyLinkedNode;
	newNode->item = value;

	// Set the next pointer to the current head
	newNode->next = singlyLinkedHead;

	// Set the head to point at the new node
	singlyLinkedHead = newNode;
}

void SinglyLinkedList::InsertNodeAtEnd(const std::string value)
{
	SinglyLinkedNode* newNode = new SinglyLinkedNode;
	newNode->item = value;

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
	if (singlyLinkedHead == nullptr)
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
	if (singlyLinkedHead == nullptr)
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
	while (secondToLast->next != nullptr)
	{
		secondToLast = secondToLast->next;
	}

	// Delete the last node
	delete secondToLast->next; // delete (second_last->next);

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
		std::cout << current->item << (current->next != nullptr) ? ", " : "";

		// Set current to next node
		current = current->next;
	}

	std::cout << "\n";
}

DoublyLinkedList::DoublyLinkedList()
{
	doublyLinkedHead->item = "";
	doublyLinkedHead->previous = nullptr;
	doublyLinkedHead->next = nullptr;
}
