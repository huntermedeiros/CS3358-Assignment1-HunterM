// Class and function delcarations for both stack implementations
#ifndef STACK_H
#define STACK_H

#include "utils.h"

// Implementation of a Stack using an array
class stackArr {
    private:
        int iSize = 1; // Smallest default Size
        int iTop = -1; // Default empty value
        int* iStackArr = NULL;

    public:
        stackArr(); // Default constructor
        ~stackArr(); // Destructor

        stackArr(int iSize); // Overloaded constructor providing size

        void push(int iNewValue); // Push element to top of stack
        void pop(); // Pop element at top of stack
        void peek(); // Returns value of top
        bool isFull(); // Returns bool based on if stack is full
        bool isEmpty(); // Returns bool based on if stack is empty
        int getSize(); // Returns size of the stack
};

// Implementation of a Stack using pointers
class stackPtr {
    private:
        Node* pStackHead = nullptr;

    public:
        stackPtr(); // Default constructor
        ~stackPtr(); // Destructor

        void push(int iNewValue); // Push element to top of stack
        void pop(); // Pop element at top of stack
        int peek(); // Returns value of top
        // bool isFull(); Not Needed because if stack is full then there are other prolems
        bool isEmpty(); // Returns bool based on if stack is empty
        int getSize();

};

#endif