#ifndef UTILS_H
#define UTILS_H

// Base inclusions
#include <iostream>
#include "stack.h"
#include "queue.h"

// Basic node structure for ADTs
struct Node {
    int iVal;
    Node* pNext = nullptr;
};

void displayMenu(std::string szMenu[], int iLength);
void menuInput(int& iUserInput);

void arrStackTest(int& iUserInput);
void ptrStackTest(int& iUserInput);
void postfixExpression();

void arrQueueTest(int& iUserInput);
void ptrQueueTest(int& iUserInput);


#endif