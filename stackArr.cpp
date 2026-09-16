#include "utils.h"
#include "stack.h"

// All code for the array based Stack
stackArr::stackArr(int iCapacity) {
    this->iCapacity = iCapacity;
    iStackArr = new int[iCapacity]; // Dynamically allocate array for stack
    std::cout << "StackArr constructor called\n"; // Testing
}

stackArr::~stackArr() {
    delete iStackArr; // Delete stack array
    iStackArr = nullptr;
    std::cout << "StackArr destructor called\n"; // Testing
}

void stackArr::push(int iNewValue) {

    if (isFull()) { // If full, output error message
        std::cout << "Stack full. Value not pushed.\n";
    }
    else {
        iTop++; // Increment top index by 1
        iStackArr[iTop] = iNewValue; // Set value at top to new value
        std::cout << "Value pushed: " << iNewValue << std::endl; // Testing
    }

}

bool stackArr::pop(int& iReturn) {
    if (isEmpty()) { // If empty, output error message
        std::cout << "Stack empty. No value to pop.\n";
        return false;
    }
    else {
        iReturn = iStackArr[iTop]; // Testing
        iTop--; // Decrement top by 1
        return true;
    }
}

void stackArr::peek() {
    if (isEmpty()) {
        std::cout << "Stack empty. No value to peek.\n";
    }
    else {
        std::cout << "Top Value: " << iStackArr[iTop] << std::endl;
    }
}

bool stackArr::isEmpty() {
    if (iTop == -1) // Check if the top index is -1
        return true;
    else    
        return false;
}

bool stackArr::isFull() {
    if (iTop == (iCapacity - 1)) // If the top index is equal to the capacity-1 
        return true;
    else
        return false;
}

int stackArr::getSize() {
    return iTop+1;
}

int stackArr::getCapacity() {
    return iCapacity;
}

// Function to test the array based stack
void arrStackTest(int& iUserInput) {
    std::string szMenuStackArr[5] = {"Array Based Stack", "Push", "Pop", "Peek", "Current Capacity/Size"};

    stackArr newStack(10); // Creation of new stack
    int iPushVal;
    int iPopVal;
    while (true) {
        displayMenu(szMenuStackArr, 5);
        intInput(iUserInput);
    
        switch(iUserInput) {
            case 1:
                intInput(iPushVal);
                newStack.push(iPushVal);
                break;
            case 2:
                newStack.pop(iPopVal);
                std::cout << "Popped: " << iPopVal << std::endl;
                break;
            case 3:
                newStack.peek();
                break;
            case 4:
                std::cout << "Capacity: " << newStack.getCapacity() << std::endl;
                std::cout << "Size: " << newStack.getSize() << std::endl << std::endl;
                break;
            case -1:
                std::cout << "Exiting array based stack testing.\n";
                return;
        }
    }
}