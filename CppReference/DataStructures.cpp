#include "DataStructures.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "Graph.h"

DataStructures::DataStructures()
{

}

void DataStructures::Demo()
{
    int choice;

    do
    {
        std::cout << "\n############################### Data Structures ###############################\n\n";

        std::cout << "CHOOSE A DEMO TO RUN:\n";
        std::cout << "[1] Queue\n"
                  << "[2] Stack\n"
                  << "[3] Singly Linked List\n"
                  << "[4] Doubly Linked List\n"
                  << "[5] Binary Tree\n"
                  << "[6] Adjacency Matrix\n"
                  << "[7] Adjacency List\n"
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

        Queue carQueue;
        Stack carStack;
        SinglyLinkedList singlyLinkedList;
        DoublyLinkedList doublyLinkedList;
        BinaryTree binaryTree;
        AdjacencyList adjacencyList;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            carQueue.Demo();
            break;
        case 2:
            carStack.Demo();
            break;
        case 3:
            singlyLinkedList.Demo();
            break;
        case 4:
            doublyLinkedList.Demo();
            break;
        case 5:
            binaryTree.Demo();
            break;
        case 6:
            
            break;
        case 7:
            adjacencyList.Demo();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";

    } while (choice != 0);
}
