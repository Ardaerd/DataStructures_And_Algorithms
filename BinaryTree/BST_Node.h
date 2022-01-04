#ifndef BINARYTREE_BST_NODE_H
#define BINARYTREE_BST_NODE_H

using namespace std;

class BST_Node {
    public:
       int data;
       BST_Node* left;
       BST_Node* right;
       BST_Node(int data);
       BST_Node* insert(BST_Node* root,int data);
       BST_Node* GetNewNode(int data);
};

#endif
