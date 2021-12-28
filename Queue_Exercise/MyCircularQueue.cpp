#include "MyCircularQueue.h"

MyCircularQueue :: MyCircularQueue(int length) {
    maxSize = length;
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

bool MyCircularQueue :: enQueue(int data) {

    if (isFull())
        return false;

    Node* newNode = new Node(data);

    if (isEmpty()) {
        this->head = newNode;
        this->tail = newNode;
    }

    else {
        tail->next = newNode;
        tail = tail->next;
    }

    size++;
    return true;
}

bool MyCircularQueue :: deQueue() {
    if (isEmpty())
        return false;

    Node* temp = this->head;
    head = head->next;
    delete temp;
    size--;
    return true;
}

string MyCircularQueue :: toString() {
    string result = "[";
    Node* temp = head;

    for (int i = 0; i < this->size-1; i++) {
        result += to_string(temp->data) + ", ";
        temp = temp->next;
    }
    result += to_string(temp->data) + "]";
    return result;
}

int MyCircularQueue :: Front() {
    return isEmpty() ? -1 : head->data;
}

int MyCircularQueue :: Rear() {
    return isEmpty() ? -1 : tail->data;
}

bool MyCircularQueue :: isFull() {
    return size == maxSize;
}

bool MyCircularQueue :: isEmpty() {
    return this->size == 0;
}
