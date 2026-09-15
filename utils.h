#ifndef UTILS_H
#define UTILS_H

// Base inclusions
#include <iostream>

// Basic node structure for ADTs
struct Node {
    int iVal;
    Node* pNext = nullptr;
};

void displayMenu(std::string szMenu[], int iLength);

#endif