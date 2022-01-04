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

int BST_Node ::findMin(BST_Node* root) {
    if (root == NULL) {
        cout << "WARNING: Tree is empty!" << endl;
        return -1;
    }

    BST_Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current->data;
}