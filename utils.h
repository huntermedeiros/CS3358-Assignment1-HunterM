#ifndef UTILS_H
#define UTILS_H

#include <iostream>

// Basic node structure for ADTs
struct Node {
    int iVal;
    Node* pNext = nullptr;
};

void displayMenu(std::string szMenu[], int iLength);
void intInput(int& iUserInput);
void postfixExpressionSolver();


#endif