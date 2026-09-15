#include "utils.h"

std::string szBreakMessage = "==============================\n";

// Function to display menus
void displayMenu(std::string szMenu[], int iLength) {
    // Menu Title and break
    std::cout << szMenu[0] << std::endl
              << szBreakMessage;
    for (int i = 1; i < iLength; i++) // Print each menu string
        std::cout << i << ". " << szMenu[i-1] << std::endl;
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

void arrStackTest(int& iUserInput) {
    std::string szMenuStackArr[5] = {"Array Based Stack", "Push", "Pop", "Peek", "Current Size"};

    

    displayMenu(szMenuStackArr, 5);
    menuInput(iUserInput);
    
    switch(iUserInput) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case -1:
            break;
    }
}
void ptrStackTest(int& iUserInput) {

}
void postfixExpression() {

}