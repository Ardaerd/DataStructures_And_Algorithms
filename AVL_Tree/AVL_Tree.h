#ifndef _AVL_Tree_
#define _AVL_Tree_

#include <string>
#include "Node.h"

using namespace std;

class AVL_Tree {
    public:
       int max(int a,int b);
       int height(Node* N);
       Node* newNode(int key);
       Node* rightRotate(Node* y);
       Node* leftRotate(Node* x);
       int getBalanceFactor(Node* N);
       Node* insertNode(Node* node, int key);
       Node* nodeWithMinValue(Node* node);
       Node* deleteNode(Node* root, int key);
       void printTree(Node* root, string indent, bool last);
};

#endif //AVL_TREE_AVL_TREE_H
