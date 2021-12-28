#include "Node.h"

Node :: Node(int data) {
    this->data = data;
    this->nextLink = nullptr;
    this->prev = nullptr;
}