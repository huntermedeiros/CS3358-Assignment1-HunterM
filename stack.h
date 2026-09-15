// Class and function delcarations for both stack implementations
#ifndef STACK_H
#define STACK_H

#include "utils.h"

// Variable ARR
class stackArr {
    private:
        int iSize;
        int iTop = -1;
        int* iStackArr = NULL;

    public:
        stackArr(); // Default Constructor
        ~stackArr(); // Destructor

        void push(int iNewValue); // Push element to top of stack
        void pop(); // Pop element at top of stack
        int peek(); // Returns value of top
        bool isFull(); // 
        bool isEmpty();
        int size();
};

class stackPtr {
    private:
        Node* pHead;

    public:
        ~stackPtr();

        void push(int iNewValue);
        void pop();
        int peek();
        int size();
        bool empty();

};

#endif