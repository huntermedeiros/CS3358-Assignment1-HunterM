#include "utils.h"
#include "queue.h"

        queueArr::queueArr() {
            iQueueArr = new int[iSize];
        }
        queueArr::~queueArr() {
            delete iQueueArr;
            iQueueArr = nullptr;
        }

        queueArr::queueArr(int iSize) {
            iQueueArr = new int[iSize];
        }

        void queueArr::enqueue() {

        }


        void queueArr::dequeue() {

        }

        void queueArr::peek() {

        }

        bool queueArr::isEmpty() {
            return false;
        }

        bool queueArr::isFull() {
            return false;
        } 

        int queueArr::currentSize() {
            return 0;
        }