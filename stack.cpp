#include "utils.h"
#include "stack.h"

stackArr::stackArr() {
    iStackArr = new int[iSize]; // Dynamically allocate array for stack
}

stackArr::~stackArr() {
    delete iStackArr; // Delete stack array
}

void stackArr::push(int iNewValue) {

    if (isFull()) { // If full, output error message
        std::cout << "Stack full. Value not pushed.\n";
    }
    else {
        iTop++; // Increment top index by 1
        iStackArr[iTop] = iNewValue; // Set value at top to new value
    }

}

void stackArr::pop() {
    if (isEmpty()) { // If empty, output error message
        std::cout << "Stack empty. No value to pop.\n";
    }
    else { 
        iTop--; // Decrement top by 1
    }
}

bool stackArr::isFull() {
    if (iTop == iSize - 1) // If the top index is 
        return false;
    else
        return true;
}

bool stackArr::isEmpty() {
    if (iTop == -1)
        return false;
    else    
        return true;
}