#include <clocale>
#include "LinkedList.h"

LinkedList :: LinkedList() {
    this->top = nullptr;
    this->head = nullptr;
}

void LinkedList :: pushNode(int data) {
    // we need to delete these nodes manually, when we don't need this link anymore
    struct Node* templink = new Node(data);

    if (head == nullptr) {
        templink->nextLink = head;
        head = templink;
    }

    templink->nextLink = top;
    top = templink;
}

int LinkedList :: end() {
    return this->top->data;
}

int LinkedList :: front() {
    return this->head->data;
}

int LinkedList :: popNode() {
    int returnValue;
    struct Node *temp;

    if (top != NULL) {
        temp = top;
        top = top->nextLink;
        returnValue = temp->data;
    }

    delete temp;
    return returnValue;
}

string LinkedList :: toString() {
    Node* temp = top;
    string result = "[";

    while (temp != NULL) {
        result += to_string(temp->data) + ", ";
        temp = temp->prev;
    }

    result +=  "]";
    return result;
}
