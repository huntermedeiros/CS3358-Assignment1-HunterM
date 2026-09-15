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
    Node* pNewNode = new Node(iNewValue, pStackHead); // Create new node and set its next to current head
    pStackHead = pNewNode; // Set the head to new node
    iSize++;
}

void stackPtr::pop() {
    if (isEmpty()) { // If empty, return error message
        std::cout << "Stack empty. No value to pop.\n";
        return;
    }

    Node* pTempNode = pStackHead; // Set a temp node to the current head
    pStackHead = pStackHead->pNext; // Set the head to the next node
    delete pTempNode; // Delete the temp containing the previous head
    iSize--;
}

void stackPtr::peek() {
    if (isEmpty()) { // If empty, return error message
        std::cout << "Stack empty. No value to peek.\n";
    }
    else {
        std::cout << "Top Value: " << pStackHead->iVal << std::endl;
    }
}

bool stackPtr::isFull() {
    return false; // Will always return false because size is limited by memory in this case
}

bool stackPtr::isEmpty() {
    if (pStackHead == nullptr)
        return true;
    else
        return false;
}

int stackPtr::getSize() {
    return iSize;
}