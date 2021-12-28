#include <clocale>
#include "Reverse_LinkedList.h"

ReverseLinkedList :: ReverseLinkedList() {
    this->size = 0;
    this->head = nullptr;
}

void ReverseLinkedList :: addAtIndex(int index, int data) {
    if (index > size)
        return;

    Node* temp = head;
    for (int i = 0; i < index; ++i)
        temp = temp->next;

    Node* temp1 = temp->next;
    temp->next = new Node(data);
    temp->next->next = temp1;
    size++;
}

Node* ReverseLinkedList ::reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* n;

    while (current != NULL) {
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
    }

    return prev;
}

