#include <iostream>

#include "utils.h"
#include "stack.h"
#include "queue.h"

int main() {
    std::string szMenuMain[4] = {"Main Menu", "Stack", "Queue", "Postfix Expressions"};
    int iUserInput = 0;
    
    do { // Main Driver loop
        displayMenu(szMenuMain, 4);
        menuInput(iUserInput);

        switch(iUserInput) {
            case 1:
                arrStackTest(iUserInput);
                break;
            case 2:
                break;
            case 3:

                break;
            case -1:
                std::cout << "Exiting program.\n";
                break;
            default:
                break;
        }

    } while (iUserInput != -1);


}