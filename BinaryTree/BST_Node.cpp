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