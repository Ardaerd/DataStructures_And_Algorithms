#ifndef _MyCircularQueue_
#define _MyCircularQueue_

#include "Node.h"

class MyCircularQueue {
    private:
        int maxSize;
        int size;
        Node* head;
        Node* tail;
    public:
        MyCircularQueue(int);
        bool enQueue(int);
        bool deQueue();
        int Front();
        int Rear();
        bool isEmpty();
        bool isFull();
        string toString();

};

#endif
