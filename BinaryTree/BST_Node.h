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
       BST_Node* Delete(BST_Node* root,int data);
       bool search(BST_Node* root,int data);
       BST_Node* findMin(BST_Node* root);
       BST_Node* findMax(BST_Node* root);
       int findHeight(BST_Node* root);
       bool IsBinarySearchTree(BST_Node* root);
       bool IsSubtreeLesser(BST_Node* root,int data);
       bool IsSubtreeGreater(BST_Node* root,int data);
       bool IsBstUtil(BST_Node* root,int minVal,int maxVal);
};

#endif
