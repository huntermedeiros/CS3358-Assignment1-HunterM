#include "utils.h"

std::string szBreakMessage = "==============================\n";

// Function to display menus
void displayMenu(std::string szMenu[], int iLength) {
    // Menu Title and break
    std::cout << szMenu[0] << std::endl
              << szBreakMessage;
    for (int i = 1; i < iLength; i++) // Print each menu string
        std::cout << i << ". " << szMenu[i] << std::endl;
    std::cout << "-1. Exit \n\n"; // Print exit string
}

// Function for getting user input for menu
void menuInput(int& iUserInput) {
    std::cout << ": ";
    while (!(std::cin >> iUserInput)) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Please enter valid choice.\n" << ": ";
    }
}