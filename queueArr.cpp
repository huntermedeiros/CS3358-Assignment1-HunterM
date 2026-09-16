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
    else { // Enqueue item at back
        iQueueArr[iBack] = iNewVal; // Insert value at back of queue
        iSize++;
        // Update back of queue
    }
}

bool queueArr::dequeue(int& iVal) {
    if (isEmpty()) { // If queue is empty, print error
        std::cout << "Queue empty. No value to dequeued.\n";
        return false;
    }
    else {
        iVal = iQueueArr[iFront];
        iFront--; // Decrement iFront to effectivaly remove element from list
        return true;
    }
}

void queueArr::peek() {
    if (isEmpty()) // If queue is empty, print error
        std::cout << "Queue empty. No value to peek.\n";
    else
        std::cout << "Front Value: " << iQueueArr[iFront] << std::endl;
}

bool queueArr::isEmpty() {
    if (iFront == iBack) // If the front is equal to the back then it is empty
        return true;
    else
        return false;
}

bool queueArr::isFull() {
    if ((iSize + 1) % iCapacity == iFront) // If taking the mod of the current size+1 to the capacity is 0 then the array is full
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