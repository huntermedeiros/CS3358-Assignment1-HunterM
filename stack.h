// Class and function delcarations for both stack implementations
#ifndef STACK_H
#define STACK_H

#include "utils.h"

// Variable ARR
class stackArr {
    private:
        int iSize = 1; // Smallest default Size
        int iTop = -1; // Default empty value
        int* iStackArr = NULL;

    public:
        stackArr(); // Default Constructor
        ~stackArr(); // Destructor

        stackArr(int iSize); // Overloaded constructor providing size

        void push(int iNewValue); // Push element to top of stack
        void pop(); // Pop element at top of stack
        int peek(); // Returns value of top
        bool isFull(); // Returns bool based on if stack is full
        bool isEmpty(); // Returns bool based on if stack is empty
        int getSize(); // Returns size of the stack
};

class stackPtr {
    private:
        Node* pStackHead;

    public:
        stackPtr();
        ~stackPtr();

        void push(int iNewValue); // Push element to top of stack
        void pop(); // Pop element at top of stack
        int peek(); // Returns value of top
        bool isFull(); // Returns bool based on if stack is full
        bool isEmpty(); // Returns bool based on if stack is empty
        int getSize(); // Returns size of the stack

};

#endif