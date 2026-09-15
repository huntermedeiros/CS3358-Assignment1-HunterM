#include "utils.h"
#include "queue.h"

        queueArr::queueArr(int iSize) {
            iQueueArr = new int[iSize];
        }
        queueArr::~queueArr() {
            delete iQueueArr; // Delete queue array and set to null
            iQueueArr = nullptr;
        }

        void queueArr::enqueue(int iNewVal) {
            if (isFull()) { // If queue is full, print error and return
                std::cout << "Queue full. Value not queued.\n";
            }
            else {
                iQueueArr[iSize-1] = iNewVal;
            }
        }


        void queueArr::dequeue() {
            if (isEmpty()) { // If queue is empty, print error and return
                std::cout << "Queue empty. Value not dequeued.\n";
            }
            else {

            }
        }

        void queueArr::peek() {

        }

        bool queueArr::isEmpty() {
            if (iFront == iBack) // If the front is equal to the back then it is empty
                return true;
            else
                return false;
        }

        bool queueArr::isFull() {
            return false;
        } 

        int queueArr::currentSize() {
            return 0;
        }