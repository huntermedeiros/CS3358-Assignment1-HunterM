// Class and function delcarations for both stack implementations
#ifndef STACK_H
#define STACK_H

struct Node;

// Implementation of a Stack using an array
class stackArr {
    private:
        int iCapacity;
        int iTop = -1; // Default empty value
        int* iStackArr = nullptr;

    public:
        stackArr(int iCapacity); // Constructor providing size
        ~stackArr(); // Destructor

        void push(int iNewValue); // Push element to top of stack
        bool pop(int& iReturn); // Pop element at top of stack
        void peek(); // Prints value of top
        bool isEmpty(); // Returns bool based on if stack is empty
        bool isFull(); // Returns bool based on if stack is full
        int getSize(); // Returns size of the stack
        int getCapacity(); // Returns capacity of stack
};

// Implementation of a Stack using pointers
class stackPtr {
    private:
        Node* pStackHead = nullptr;
        int iSize = 0;

    public:
        stackPtr(); // Default constructor
        ~stackPtr(); // Destructor

        void push(int iNewValue); // Push element to top of stack
        bool pop(int& iReturn); // Pop element at top of stack
        void peek(); // Prints value of top
        bool isEmpty(); // Returns bool based on if stack is empty
        bool isFull(); // Not needed because if stack is full then you have no memory
        int getSize(); // Returns size of the stack
};

void arrStackTest(int& iUserInput);
void ptrStackTest(int& iUserInput);

#endif