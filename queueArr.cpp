#include "utils.h"
#include "queue.h"

queueArr::queueArr(int iCapacity) { // Create new queueArr given capacity
    this->iCapacity = iCapacity;
    iQueueArr = new int[iCapacity];
}
queueArr::~queueArr() { // Delete queue array and set to null
    delete iQueueArr; 
    iQueueArr = nullptr;
}

void queueArr::enqueue(int iNewVal) {
    if (isFull()) { // If queue is full, print error and return
        std::cout << "Queue full. Value not enqueued.\n";
    }
    else if (isEmpty()) {
        iFront = iBack = 0;
        iQueueArr[iBack] = iNewVal;
    }
    else { // Enqueue item at back
        iBack = (iBack + 1) % iCapacity; // Update back
        iQueueArr[iBack] = iNewVal;
    }
}

bool queueArr::dequeue(int& iVal) {
    if (isEmpty()) { // If queue is empty, print error
        std::cout << "Queue empty. No value to dequeued.\n";
        return false;
    }

    iVal = iQueueArr[iFront]; // Update iVal with the current front value
    if (iFront == iBack) // If empty set to empty sentinels
        iFront = iBack = -1;
    else // Else, update the front
        iFront = (iFront + 1) % iCapacity;
    return true;
}

void queueArr::peek() {
    if (isEmpty()) // If queue is empty, print error
        std::cout << "Queue empty. No value to peek.\n";
    else
        std::cout << "Front Value: " << iQueueArr[iFront] << std::endl;
}

bool queueArr::isEmpty() {
    if (iFront == -1 || iBack == -1)
        return true;
    else
        return false;
}

// Array is full when the back reaches around to the front when attempting to add another value
bool queueArr::isFull() {
    if ((iBack + 1) % iCapacity == iFront)
        return true;
    else
        return false;            
} 

int queueArr::getSize() { // Returns size
    return iSize;
}

int queueArr::getCapacity() {
    return iCapacity;
}

// Testing function
void arrQueueTest(int& iUserInput) {
    std::string szMenuQueueArr[5] = {"Array Based Queue", "Enqueue", "Dequeue", "Peek", "Current Capacity/Size"};

    queueArr newQueue(10); // Creation of new stack
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
                std::cout << "Capacity: " << newQueue.getCapacity() << std::endl;
                std::cout << "Size: " << newQueue.getSize() << std::endl;
                break;
            case -1:
                std::cout << "Exiting array based queue testing.\n";
                return;
        }
    }
}