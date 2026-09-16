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
    bool bIsInvalid = false; // To keep track of invalid expressions

    std::cout << "\nPostfix Expression Evaluator\n" << szBreakMessage;
    std::cout << "Enter operand \"0-9\" and operators \"+, -, *, /\" one by one.\n";
    std::cout << "Enter \"=\" to indicate the end of the expression\n";
    
    // Input character
    // if input is opperator, pop two previous and push the result onto stack
        // If Unable to pop two previous flag as a invalid expression
    // else if the input is a number, push number onto stack

    do {
        std::cout << ": "; // User input
        std::cin >> cUserInput;

        if (cUserInput == '=')
            break;

        // Check to see if input is an operator
        if (cUserInput == '+' || cUserInput == '-' || cUserInput == '*' || cUserInput == '/') {
            int iX, iY;
            if (!(expressionStack.pop(iY) && expressionStack.pop(iX))) {
                bIsInvalid = true;
                std::cout << "Error. Unable to complete operation.\n";
                break;
            }

            // Calcuate operation result and push it to the stack
            switch (cUserInput) { // 
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
        }
        // Else check if input is an operand
        else if (cUserInput >= '0' && cUserInput <= '9') {
            expressionStack.push(static_cast<int>(cUserInput - '0')); // Pushes integer value onto stack
        }
    } while (cUserInput != '=');

    if (expressionStack.getSize() != 1) {
        bIsInvalid = true;
    }
    if (bIsInvalid == true)
        std::cout << "Expression invalid\n";
    else {
        int iResult;
        expressionStack.pop(iResult);
        std::cout << "Result: " << iResult << std::endl;
    }

    std::cout << "Exiting postfix expression evaluator\n";
}
