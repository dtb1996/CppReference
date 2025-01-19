// CppReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"
#include "Stack.h"

int main()
{
    int choice;

    std::cout << "\n################################## MAIN MENU ##################################\n\n";

    do
    {
        std::cout << "CHOOSE A DEMO TO RUN:\n";
        std::cout << "[1] Queue\n"
                  << "[2] Stack\n"
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
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";

    } while (choice != 0);

    return 0;
}
