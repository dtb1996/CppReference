// CppReference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"

int main()
{
    int choice;

    do
    {
        std::cout << "CHOOSE A DEMO TO RUN:\n";
        std::cout << "[1] Queue\n"
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

        switch (choice)
        {
        case 1:
            Queue carQueue;
            carQueue.Demo();
        }

        std::cout << "\n";

    } while (choice != 0);

    return 0;
}
