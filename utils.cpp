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
void intInput(int& iUserInput) {
    std::cout << ": ";
    while (!(std::cin >> iUserInput)) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Please enter valid input.\n" << ": ";
    }
}

void postfixExpressionSolver() {
    /*
        Push character into stack and check if it is an operation
        Once an operation is pushed, pop it, and store it
        Then pop the two previous values which should be numbers and store them.
        The first number value popped will be the right side of the operation while the last value popped will be the left side.
        You can use a switch statement to determine operation then use the specific case to operate on the values.
        Once operated on, push the result of the operation into the stack.
    */
    stackPtr expressionStack;
    char cUserInput;
    bool bOperationFlag = false; // Flag to keep track of when operations should appear

    std::cout << "Postfix Expression Evaluator\n" << szBreakMessage << std::endl;
    do {
        // Enter Value
        if (expressionStack.getSize() == 2)
            bOperationFlag = true;
        
        if (bOperationFlag) { // If operation, ask for operation
            std::cout << "Enter operator \"+, -, *, /\" ('n' to exit): ";
            std::cin >> cUserInput;
            if (cUserInput == 'n') { // Exit early if n
                std::cout << "Exiting postfix expression evaluator\n";
                return;
            }
        }
        else { // Otherwise, ask for number
            std::cout << "Enter nonnegative value 0-9 ('n' to exit): ";
            std::cin >> cUserInput;

            if (cUserInput == 'n') { // Exit early if n
                std::cout << "Exiting postfix expression evaluator\n";
                return;
            }
        }
        
        
    } while (cUserInput != 'n');
}
