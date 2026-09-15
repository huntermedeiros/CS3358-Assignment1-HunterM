// Class and function delcarations for both stack implementations
#ifndef QUEUE_H
#define QUEUE_H

#include "utils.h"

// Implementation of a Queue using an array
class queueArr {
    private:
        int iSize;
        int iCapacity;
        int iFront = 0;
        int iBack = 0;
        int* iQueueArr = nullptr;

    public:
        queueArr(int iCapacity); // Constructor providing size
        ~queueArr(); // Destructor

        void enqueue(int iNewVal); // Enqueue element
        void dequeue(); // Dequeue element
        void peek(); // Print front value
        bool isEmpty(); // Returns bool based on if queue is empty
        bool isFull(); // Returns bool based on if queue is full
        int getSize(); // Returns size of Queue
};

// Implementation of a Queue using pointers
class queuePtr {
    private:
        Node* pQueueHead = nullptr; // Front of the queue
        Node* pQueueTail = nullptr; // Back of the queue
        int iSize = 0;

    public:
        queuePtr();
        ~queuePtr();

        void enqueue(int iNewVal); // Enqueue element
        void dequeue(); // Dequeue element
        void peek(); // Print front value
        bool isEmpty(); // Returns bool based on if queue is empty
        bool isFull(); // Returns bool based on if queue is full
        int getSize(); // Returns size of Queue
};

#endif