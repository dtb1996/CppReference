#include "BinaryTree.h"
#include <queue>

void BinaryTree::InsertNode(const std::string value)
{
	Node* newNode = new Node(value);

	// Check if this is the first node to be added
	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	std::queue<Node*> q;
	q.push(root);

	// Find the next available position in the tree to add the new node
	while (!q.empty())
	{
		Node* current = q.front();
		q.pop();

		if (current->left == nullptr)
		{
			current->left = newNode;
			return;
		}
		else
		{
			q.push(current->left);
		}

		if (current->right == nullptr)
		{
			current->right = newNode;
			return;
		}
		else
		{
			q.push(current->right);
		}
	}
}

void BinaryTree::DeleteNode(const std::string value)
{
	root = DeleteRecursive(root, value);
}

bool BinaryTree::Search(const std::string value)
{
	return SearchRecursive(root, value);
}

void BinaryTree::PreOrderTraversal()
{
	PreOrderRecursive(root);

	std::cout << "\n";
}

void BinaryTree::InOrderTraversal()
{
	InOrderRecursive(root);

	std::cout << "\n";
}

void BinaryTree::PostOrderTraversal()
{
	PostOrderRecursive(root);

	std::cout << "\n";
}

void BinaryTree::LevelOrderTraversal()
{
	if (root == nullptr)
	{
		return;
	}

	std::queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* current = q.front();
		q.pop();

		std::cout << current->item << " ";

		if (current->left != nullptr)
		{
			q.push(current->left);
		}

		if (current->right != nullptr)
		{
			q.push(current->right);
		}
	}
}

void BinaryTree::Demo()
{
	std::cout << "\n############################ BINARY TREE DEMO ##################################\n\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Insert node\n"
				  << "[2] Delete node\n"
				  << "[3] Search for an item\n"
				  << "[4] Perform pre-order traversal\n"
				  << "[5] Perform in-order traversal\n"
				  << "[6] Perform post-order traversal\n"
				  << "[7] Perform level-order traversal\n"
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
			std::cout << "Enter an item to add to the tree:\n";
			std::cin >> item;
			InsertNode(item);
			break;
		case 2:
			std::cout << "Enter an item to remove from the tree:\n";
			std::cin >> item;
			DeleteNode(item);
			break;
		case 3:
			std::cout << "Enter an item to search for:\n";
			std::cin >> item;
			std::cout << "The item was " << (Search(item) ? "" : "not ") << "found\n";
			break;
		case 4:
			std::cout << "Performing pre-order traversal:\n";
			PreOrderTraversal();
			break;
		case 5:
			std::cout << "Performing in-order traversal:\n";
			InOrderTraversal();
			break;
		case 6:
			std::cout << "Performing post-order traversal:\n";
			PostOrderTraversal();
			break;
		case 7:
			std::cout << "Performing level-order traversal:\n";
			LevelOrderTraversal();
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";

	} while (choice != 0);
}

Node* BinaryTree::DeleteRecursive(Node* current, const std::string value)
{
	// Check if current is invalid
	if (current == nullptr)
	{
		return nullptr;
	}

	// Check if the current node has the specified value
	if (current->item == value)
	{
		// If current left and right pointers are null, it is safe to delete this node
		if (current->left == nullptr && current->right == nullptr)
		{
			delete current;
			return nullptr;
		}


		if (current->left == nullptr)
		{
			Node* tempNode = current->left;
			delete current;
			return tempNode;
		}

		Node* successor = FindMinValueNode(current->right);

		current->item = successor->item;
		current->right = DeleteRecursive(current->right, successor->item);
	}
	else
	{
		current->left = DeleteRecursive(current->left, value);
		current->right = DeleteRecursive(current->right, value);
	}

	return current;
}

Node* BinaryTree::FindMinValueNode(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}

bool BinaryTree::SearchRecursive(Node* current, const std::string value)
{
	// Check if current node is invalid
	if (current == nullptr)
	{
		return false;
	}

	// Check if the current node has value
	if (current->item == value)
	{
		return true;
	}

	// Continue searching the tree for value
	return SearchRecursive(current->left, value) || SearchRecursive(current->right, value);
}

void BinaryTree::PreOrderRecursive(Node* node)
{
	if (node != nullptr)
	{
		std::cout << node->item << " ";

		PreOrderRecursive(node->left);

		PreOrderRecursive(node->right);
	}
}

void BinaryTree::InOrderRecursive(Node* node)
{
	if (node != nullptr)
	{
		InOrderRecursive(node->left);

		std::cout << node->item << " ";

		InOrderRecursive(node->right);
	}
}

void BinaryTree::PostOrderRecursive(Node* node)
{
	if (node != nullptr)
	{
		PostOrderRecursive(node->left);

		PostOrderRecursive(node->right);

		std::cout << node->item << " ";
	}
}
