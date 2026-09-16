#include <iostream>

#include "utils.h"
#include "stack.h"
#include "queue.h"

int main() {
    std::string szMenuMain[4] = {"Main Menu", "Stack", "Queue", "Postfix Expressions"};
    std::string szMenuStack[3] = {"Stacks", "Array", "Pointer"};
    std::string szMenuQueue[3] = {"Queues", "Array", "Pointer"};
    int iUserInput = 0;
    std::string szExpression;

    while (true) { // Main Driver loop
        displayMenu(szMenuMain, 4);
        intInput(iUserInput);

        switch(iUserInput) {
            case 1: // Stacks
                displayMenu(szMenuStack, 3);
                intInput(iUserInput);
                switch (iUserInput) {
                    case 1: // Array based stack
                        arrStackTest(iUserInput);
                        break;
                    case 2: // Pointer based stack
                        ptrStackTest(iUserInput);
                        break;
                    case -1:
                        break;
                }
                break;
            case 2: // Queues
                displayMenu(szMenuQueue, 3);
                intInput(iUserInput);
                switch (iUserInput) {
                    case 1: // Array based queue
                        arrQueueTest(iUserInput);
                        break;
                    case 2: // Pointer based queue
                        ptrQueueTest(iUserInput);
                        break;
                    case -1:
                        break;
                }
                break;
            case 3: // Postfix Expression Solver
                postfixExpressionSolver();
                break;
            case -1:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                break;
        }
    }


}