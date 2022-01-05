#include <clocale>
#include "Node.h"

Node :: Node(int key) {
    this->key = key;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
}

