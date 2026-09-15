#include "utils.h"
#include "queue.h"

queueArr::queueArr(int iCapacity) { // Create new queueArr given capacity
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
        std::cout << "Queue empty. Value not dequeued.\n";
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