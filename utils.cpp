#include "utils.h"

std::string szBreakMessage = "==============================\n";

// Function to display menus
void displayMenu(std::string szMenu[], int iLength) {
    // Menu Title and break
    std::cout << std::endl << szMenu[0] << std::endl
              << szBreakMessage;
    for (int i = 1; i < iLength; i++) // Print each menu string
        std::cout << i << ". " << szMenu[i] << std::endl;
    std::cout << "-1. Exit \n"; // Print exit string
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
    stackPtr expressionStack;
    char cUserInput;
    bool bOperationFlag = false; // Flag to keep track of when operations should appear

    std::cout << "\nPostfix Expression Evaluator\n" << szBreakMessage;
    do {
        // Enter Value
        if (expressionStack.getSize() == 2)
            bOperationFlag = true;
        
        if (bOperationFlag) { // If operation, ask for operation
            std::cout << "Enter operator \"+, -, *, /\" ('n' to exit): ";
            std::cin >> cUserInput;
            if (cUserInput == 'n')  // Exit early if n
                break;

            // Check if value is correct, exit if not
            if (!(cUserInput == '+' || cUserInput == '-' || cUserInput == '*' || cUserInput == '/'))
            {
                std::cout << "Error, invalid value as input\n";
                break;
            }

            int iX, iY;
            if (!expressionStack.pop(iY) || !expressionStack.pop(iX)) {
                std::cout << "Error. Invalid expression\n";
                break;
            }
            
            switch(cUserInput) { // Base on operation, push operation output to stack
                case '+':
                    expressionStack.push(iX + iY);
                    break;
                case '-':
                    expressionStack.push(iX - iY);
                    break;
                case '*':
                    expressionStack.push(iX * iY);
                    break;
                case '/':
                    expressionStack.push(iX / iY);
                    break;
            }

            bOperationFlag = false;
            
        }
        else { // Otherwise, ask for number
            std::cout << "Enter nonnegative value \"0-9\" ('n' to exit): ";
            std::cin >> cUserInput;

            if (cUserInput == 'n') { // Exit early if n
                break;
            }

            if (cUserInput < '0' || cUserInput > '9') { // Check if number is in the range of 0-9
                std::cout << "Error, invalid value as input\n";
                break;
            }

            expressionStack.push(static_cast<int>(cUserInput-'0'));
        }
        
        
    } while (cUserInput != 'n');

    int iFinal;
    if (expressionStack.pop(iFinal) && expressionStack.isEmpty())
        std::cout << "Expression Value: " << iFinal << std::endl;
    else
        std::cout << "Incomplete Expression\n";


    std::cout << "Exiting postfix expression evaluator\n";
}
