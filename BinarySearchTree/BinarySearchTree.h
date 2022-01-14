#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include "Node.h"

using namespace std;

class BST {
    public:
       int depth(Node* node);
       int countNumNode(Node* root);
       Node* newNode(int data);
       void inorder(Node* root);
       void preorder(Node* root);
       void postorder(Node* root);
       Node* insert(Node* root, int data);
       Node* minValueNode(Node* root);
       Node* deleteNode(Node* root, int data);
       bool isFullBinaryTree(Node* root);
       bool isPerfectBinaryTree(Node* root, int depth,int level);
       bool isPerfect(Node* root);
       bool checkComplete(Node* root,int index, int numberNodes);
       bool isBalanced(Node* root);
       int height(Node* node);
};

#endif
