#include "utils.h"

// Node struct used for ptr based ADT's
struct Node {
    int iVal;
    Node* pNext;
};

void displayMenu(string szMenuArr, int iLength) {
    for (int i = 0; i < iLength; i++)
        cout << i+1 << ". " << szMenuArr[i];
}

