#include "utils.h"
#include "queue.h"

queuePtr::queuePtr() {
    pQueueHead = nullptr; // Initialize empty queue
    pQueueTail = nullptr;
    iSize = 0;
}

queuePtr::~queuePtr() {
    Node* pCurrent = pQueueHead; // Start at queue head
    Node* pNextDel = nullptr; // Pointer for next 

    while (pCurrent != nullptr) // Check for current being null
    {
        pNextDel = pCurrent->pNext; // Get next value
        delete pCurrent; // Delete current and move to next
        pCurrent = pNextDel;
    }

    pQueueHead = nullptr; // At end make sure queue head and tail are null
    pQueueTail = nullptr;
}

void queuePtr::enqueue(int iNewVal) {
    if (isEmpty()) { // If empty, initialize queue with new value
        pQueueHead = new Node(iNewVal, nullptr);
        pQueueTail = pQueueHead;
    }
    else {
        pQueueTail->pNext = new Node(iNewVal, nullptr); // Create new node on current tails next pointer
        pQueueTail = pQueueTail->pNext; // Update tail to the current tail's next pointer
    }
}

bool queuePtr::dequeue(int& iVal) {
    if (isEmpty()) { // If empty, print error
        std::cout << "Queue empty. No value to dequeue\n";
        return false;
    }
    else {
        Node* pToDel = pQueueHead; // Store current head
        pQueueHead = pQueueHead->pNext; // Update queue's head to its next value
        iVal = pToDel->iVal;
        delete pToDel; // Delete old head
        return true;
    }  
}

void queuePtr::peek() {
    if (isEmpty())
        std::cout << "Queue empty. No value to peek\n";
    else
        std::cout << "Front Value: " << pQueueHead->iVal << std::endl;
}

bool queuePtr::isEmpty() {
    if (pQueueHead == nullptr)
        return true;
    else
        return false;
}

bool queuePtr::isFull() {
    return false;
} 

int queuePtr::getSize() {
    return iSize;
}

// Testing function
void ptrQueueTest(int& iUserInput) {
    std::string szMenuQueueArr[5] = {"Pointer Based Queue", "Enqueue", "Dequeue", "Peek", "Current Size"};

    queuePtr newQueue; // Creation of new queue
    int iEnqueueVal, iDequeueVal;
    while (true) {
        displayMenu(szMenuQueueArr, 5);
        intInput(iUserInput);
    
        switch(iUserInput) {
            case 1:
                std::cout << "Enter Value";
                intInput(iEnqueueVal);
                newQueue.enqueue(iEnqueueVal);
                break;
            case 2:
                if (newQueue.dequeue(iDequeueVal))
                    std::cout << "Dequeued: " << iDequeueVal << std::endl;
                break;
            case 3:
                newQueue.peek();
                break;
            case 4:
                std::cout << "Size: " << newQueue.getSize() << std::endl;
                break;
            case -1:
                std::cout << "Exiting pointer based queue testing.\n";
                return;
        }
    }
}