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

void queuePtr::dequeue() {
    if (isEmpty()) { // If empty, print error
        std::cout << "Queue empty. No value to dequeue\n";
    }
    else {
        Node* pToDel = pQueueHead; // Store current head
        pQueueHead = pQueueHead->pNext; // Update queue's head to its next value
        delete pToDel; // Delete old head
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