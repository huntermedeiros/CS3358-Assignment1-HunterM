#include "utils.h"
#include "stack.h"

// All code for the array based Stack

stackArr::stackArr() {
    iStackArr = new int[iSize]; // Dynamically allocate array for stack
    std::cout << "StackArr constructor called\n"; // Testing
}

stackArr::~stackArr() {
    delete iStackArr; // Delete stack array
    iStackArr = nullptr;
    std::cout << "StackArr destructor called\n"; // Testing
}

stackArr::stackArr(int iSize) {
    this->iSize = iSize;
    iStackArr = new int[iSize]; // Dynamically allocate array for stack
    std::cout << "StackArr constructor called\n"; // Testing
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

void stackArr::pop() {
    if (isEmpty()) { // If empty, output error message
        std::cout << "Stack empty. No value to pop.\n";
    }
    else {
        std::cout << "Value popped: " << iStackArr[iTop] << std::endl; // Testing
        iTop--; // Decrement top by 1
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
        return false;
    else    
        return true;
}

bool stackArr::isFull() {
    if (iTop == iSize - 1) // If the top index is 
        return false;
    else
        return true;
}

int stackArr::getSize() {
    return iTop+1;
}