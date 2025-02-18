#include "Graph.h"

AdjacencyMatrix::AdjacencyMatrix()
{

}

AdjacencyList::AdjacencyList()
{
	
}

void AdjacencyList::AddEdge(const int source, const int destination)
{
	if (!HasVertex(source))
	{
		adjacencyList.resize(adjacencyList.size() + 1);
	}

	adjacencyList[source].push_back(destination);
}

bool AdjacencyList::HasVertex(const int vertex)
{
	return vertex >= 0 && vertex < adjacencyList.size();
}

void AdjacencyList::ClearAdjacencyList()
{
	adjacencyList.clear();
}

void AdjacencyList::PrintAdjacencyList() const
{
	for (int i = 0; i < adjacencyList.size(); ++i)
	{
		std::cout << "Vertex " << i << ": ";

		for (int j = 0; j < adjacencyList[i].size(); ++j)
		{
			std::cout << adjacencyList[i][j] << " > ";
		}

		std::cout << "NULL" << "\n";
	}
}

void AdjacencyList::Demo()
{
	std::cout << "\n############################## ADJACENCY LIST DEMO ####################################\n";

	int choice;

	do
	{
		std::cout << "\nCHOOSE AN ACTION:\n";
		std::cout << "[1] Add a new edge\n"
				  << "[2] Clear the list\n"
				  << "[3] Print the list\n"
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

		int source = 0;
		int destination = 0;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			std::cout << "Enter the source vertex:\n";
			std::cin >> source;
			std::cout << "Enter the destination vertex:\n";
			std::cin >> destination;
			AddEdge(source, destination);
			break;
		case 2:
			std::cout << "Clearing the list:\n";
			ClearAdjacencyList();
			break;
		case 3:
			std::cout << (adjacencyList.empty() ? "The list is empty.\n" : "Printing the list:\n");
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}

		std::cout << "\n";
		PrintAdjacencyList();

	} while (choice != 0);
}
