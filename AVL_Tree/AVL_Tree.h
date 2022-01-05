#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H

class AVTreeNode {
    public:
       int max(int a,int b);
       int height(Node* N);
       Node* newNode(int key);
       Node* rightRotation(Node* y);
       Node* leftRotate(Node* x);
       int getBalanceFactor(Node* N);
       Node* insertNode(Node* node, int key);
       Node* nodeWithMinValue(Node* node);
       Node* deleteNode(Node* root, int key);
       void printTree(Node* root, string indent, bool last);
};

#endif //AVL_TREE_AVL_TREE_H
