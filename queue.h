// Class and function delcarations for both stack implementations
#ifndef QUEUE_H
#define QUEUE_H

#include "utils.h"

// Implementation of a Queue using an array
class queueArr {
    private:
        int iSize = 1; // Smallest default Size
        int iFront = 0;
        int iBack = 0;
        int* iQueueArr = NULL;

    public:
        queueArr(); // Default constructor
        ~queueArr(); // Destructor

        queueArr(int iSize); // Overloaded constructor providing size

        void enqueue(); // Enqueue element
        void dequeue(); // Dequeue element
        void peek(); // Print front value
        bool isEmpty(); // Returns bool based on if queue is empty
        bool isFull(); // Returns bool based on if queue is full
        int currentSize(); // Returns size of Queue
};

// Implementation of a Queue using pointers
class queuePtr {
    private:
        Node* pStackHead = nullptr;
        int iSize = 0;

    public:
        queuePtr();
        ~queuePtr();

        void enqueue(); // Enqueue element
        void dequeue(); // Dequeue element
        void peek(); // Print front value
        bool isEmpty(); // Returns bool based on if queue is empty
        bool isFull(); // Returns bool based on if queue is full
        int currentSize(); // Returns size of Queue
};

#endif