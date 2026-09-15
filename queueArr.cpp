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
    else {
        iBack = (iFront + iSize) % iCapacity; // The back of the queueu is the mod of the front + size by the capacity
        iQueueArr[iBack] = iNewVal; // Insert value at back of queue
        iSize++;
    }
}

void queueArr::dequeue() {
    if (isEmpty()) { // If queue is empty, print error
        std::cout << "Queue empty. No value to dequeued.\n";
    }
    else {
        iFront--; // Decrement iFront to effectivaly remove element from list
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
    if ((iSize + 1) % iCapacity == 0) // If taking the mod of the current size+1 to the capacity is 0 then the array is full
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

void arrQueueTest(int& iUserInput) {
    std::string szMenuQueueArr[5] = {"Array Based Queue", "Enqueue", "Dequeue", "Peek", "Current Capacity/Size"};

    queueArr newQueue(10); // Creation of new stack
    int iEnqueueValue;
    while (true) {
        displayMenu(szMenuQueueArr, 5);
        intInput(iUserInput);
    
        switch(iUserInput) {
            case 1:
                intInput(iEnqueueValue);
                newQueue.enqueue(iEnqueueValue);
                break;
            case 2:
                newQueue.dequeue();
                break;
            case 3:
                newQueue.peek();
                break;
            case 4:
                std::cout << "Capacity: " << newQueue.getCapacity() << std::endl;
                std::cout << "Size: " << newQueue.getSize() << std::endl << std::endl;
                break;
            case -1:
                std::cout << "Exiting pointer based stack testing.\n";
                return;
        }
    }
}