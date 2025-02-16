// CppReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataStructures.h"

int main()
{
    int choice;

    do
    {
        std::cout << "\n################################## MAIN MENU ##################################\n\n";

        std::cout << "CHOOSE A DEMO TO RUN:\n";
        std::cout << "[1] DataStructures\n"
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

        DataStructures dataStructures;

        switch (choice)
        {
            case 0:
                break;
            case 1:
                dataStructures.Demo();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";

    } while (choice != 0);

    return 0;
}
