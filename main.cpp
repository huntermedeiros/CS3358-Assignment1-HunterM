#include <iostream>

#include "utils.h"
#include "stack.h"
#include "queue.h"

int main() {
    std::string szMenuMain[4] = {"Main Menu", "Stack", "Queue", "Postfix Expressions"};
    std::string szMenuStack[3] = {"Stacks", "Array", "Pointer"};
    std::string szMenuQueue[3] = {"Queues", "Array", "Pointer"};
    int iUserInput = 0;
    
    while (true) { // Main Driver loop
        displayMenu(szMenuMain, 4);
        intInput(iUserInput);

        switch(iUserInput) {
            case 1:
                displayMenu(szMenuStack, 3);
                intInput(iUserInput);
                switch (iUserInput) {
                    case 1:
                        arrStackTest(iUserInput);
                        break;
                    case 2:
                        ptrStackTest(iUserInput);
                        break;
                    case -1:
                        break;
                }
                break;
            case 2:
                displayMenu(szMenuQueue, 3);
                intInput(iUserInput);
                switch (iUserInput) {
                    case 1:
                        arrQueueTest(iUserInput);
                        break;
                    case 2:
                        break;
                    case -1:
                        break;
                }
                break;
            case 3:

                break;
            case -1:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                break;
        }
    }


}