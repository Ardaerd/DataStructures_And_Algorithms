#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include "Node.h"

using namespace std;

class BST {
    public:
       Node* newNode(int data);
       void inorder(Node* root);
       Node* insert(Node* root, int data);
       Node* minValueNode(Node* root);
       Node* deleteNode(Node* root, int data);
};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
