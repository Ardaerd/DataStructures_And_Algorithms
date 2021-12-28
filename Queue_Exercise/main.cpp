#include <iostream>
#include "MyCircularQueue.h"

int main() {

    MyCircularQueue* queue = new MyCircularQueue(5);

    queue->enQueue(1);
    queue->enQueue(2);
    queue->enQueue(3);
    queue->enQueue(4);
    queue->enQueue(5);
    queue->deQueue();
    queue->enQueue(6);
    queue->deQueue();
    queue->enQueue(7);

    cout << queue->Front() << endl;
    cout << queue->Rear() << endl;

   cout << queue->toString() << endl;

    return 0;
}
