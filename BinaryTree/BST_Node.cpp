#include <iostream>
#include "BST_Node.h"

BST_Node :: BST_Node (int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

BST_Node* BST_Node :: GetNewNode(int data) {
    BST_Node* newNode = new BST_Node(data);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bool BST_Node :: search(BST_Node* root,int data) {
    if (root == NULL)
        return false;

    else if (root->data == data)
        return true;

    else if (data <= root->data)
        return search(root->left,data);

    else
        return search(root->right,data);
}

BST_Node* BST_Node :: insert(BST_Node* root, int data) {
    if (root == NULL)
        root = GetNewNode(data);

    else if (data <= root->data) {
        if (root->left == NULL) {
            root->left = insert(root->left,data);
            cout << "left child of " << root->data << ": " << root->left->data << endl;
        }
        else
            root->left = insert(root->left,data);
    }

    else {
        if (root->right == NULL) {
            root->right = insert(root->right,data);
            cout << "right child of " << root->data << ": " << root->right->data << endl;
        }
        else
            root->right = insert(root->right,data);
    }

    return root;
}

int BST_Node :: findMax(BST_Node *root) {
    if (root == NULL) {
        cout << "WARNING: Tree is empty!" << endl;
        return -1;
    }

    BST_Node* current = root;

    while (current->right != NULL)
        current = current->right;

    return current->data;
}

int BST_Node :: findMin(BST_Node* root) {
    if (root == NULL) {
        cout << "WARNING: Tree is empty!" << endl;
        return -1;
    }

    BST_Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current->data;
}

int BST_Node :: findHeight(BST_Node *root) {
    if (root == NULL)
        return -1;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

bool BST_Node ::IsSubtreeLesser(BST_Node *root, int data) {
    if (root == NULL)
        return true;

    if ((root->data <= data) && IsSubtreeLesser(root->left,data) && IsSubtreeLesser(root->right,data))
        return true;

    else
        return false;
}

bool BST_Node :: IsSubtreeGreater(BST_Node *root, int data) {
    if (root == NULL)
        return true;

    if ((root->data > data) && IsSubtreeGreater(root->left,data) && IsSubtreeGreater(root->right,data))
        return true;

    else
        return false;
}

bool BST_Node :: IsBinarySearchTree(BST_Node *root) {
    if (root == NULL)
        return true;

    if (IsSubtreeLesser(root->left,root->data) && IsSubtreeGreater(root->right,root->data)
         && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
        return true;

    else
        return false;
}

// It is a different approach to check is it a binary tree or not
bool BST_Node :: IsBstUtil(BST_Node* root,int minVal,int maxVal) {
    if (root == NULL)
        return true;

    if ((root->data > minVal) && (root->data < maxVal) && IsBstUtil(root->left,minVal,root->data)
        && IsBstUtil(root->right,root->data,maxVal))
        return true;

    else
        return false;
}