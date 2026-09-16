#include "utils.h"
#include "stack.h"

stackPtr::stackPtr() {
    pStackHead = nullptr;
}

stackPtr::~stackPtr() {
    Node* pCurrent = pStackHead; // Start at stack head
    Node* pNextDel = nullptr; // Pointer for next 

    while (pCurrent != nullptr) // Check for current being null
    {
        pNextDel = pCurrent->pNext; // Get next value
        delete pCurrent; // Delete current and move to next
        pCurrent = pNextDel;
    }

    pStackHead = nullptr; // At end make sure stack head is null
}

void stackPtr::push(int iNewValue) {
    Node* pNewNode = new Node(iNewValue); // Create new node and set its next to current head
    pNewNode->pNext = pStackHead;
    pStackHead = pNewNode; // Set the head to new node
    iSize++;
}

bool stackPtr::pop(int& iReturn) {
    if (isEmpty()) { // If empty, return error message
        std::cout << "Stack empty. No value to pop.\n";
        return false;
    }

    Node* pTempNode = pStackHead; // Set a temp node to the current head
    pStackHead = pStackHead->pNext; // Set the head to the next node
    iReturn = pTempNode->iVal; // Sets parameter to popped value
    delete pTempNode; // Delete the temp containing the previous head
    iSize--;
    return true;
}

void stackPtr::peek() {
    if (isEmpty()) { // If empty, return error message
        std::cout << "Stack empty. No value to peek.\n";
    }
    else {
        std::cout << "Top Value: " << pStackHead->iVal << std::endl;
    }
}

bool stackPtr::isEmpty() {
    if (pStackHead == nullptr)
        return true;
    else
        return false;
}

bool stackPtr::isFull() {
    return false; // Will always return false because size is limited by memory in this case
}

int stackPtr::getSize() {
    return iSize;
}

// Testing function
void ptrStackTest(int& iUserInput) {
    std::string szMenuStackArr[5] = {"Pointer Based Stack", "Push", "Pop", "Peek", "Current Size"};

    stackPtr newStack; // Creation of new stack
    int iPushVal;
    int iPopVal;
    while (true) {
        displayMenu(szMenuStackArr, 5);
        intInput(iUserInput);
    
        switch(iUserInput) {
            case 1:
                std::cout << "Enter Value";
                intInput(iPushVal);
                newStack.push(iPushVal);
                break;
            case 2:
                if(newStack.pop(iPopVal))
                    std::cout << "Popped: " << iPopVal << std::endl;
                break;
            case 3:
                newStack.peek();
                break;
            case 4:
                std::cout << "Size: " << newStack.getSize() << std::endl << std::endl;
                break;
            case -1:
                std::cout << "Exiting pointer based stack testing.\n";
                return;
        }
    }
}