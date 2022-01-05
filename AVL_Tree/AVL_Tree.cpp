#include <iostream>
#include "AVL_Tree.h"

// Calculate height
int AVL_Tree :: height(Node* N) {
    if (N == NULL) 
        return 0;
    return N->height;
}

int AVL_Tree :: max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

// New node creation
Node* AVL_Tree :: newNode(int key) {
    Node* node = new Node(key);
    return node;
}

// Rotate right
Node* AVL_Tree :: rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    
    return x;
}

// Rotate left
Node* AVL_Tree :: leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    
    return y;
}

// Get the Balance factor of each node
int AVL_Tree :: getBalanceFactor(Node* N) {
    if (N == NULL) 
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a Node
Node* AVL_Tree :: insertNode(Node* node, int key) {
    // Find the correct position and insert the node
    if (node == NULL) 
        return newNode(key);
    
    if (key < node->key)
        node->left = insertNode(node->left, key);
    
    else if (key > node->key) 
        node->right = insertNode(node->right,key);
    
    else 
        return node;
    
    // Update the balance factor of each node and balance the tree
    node->height = 1 + max(height(node->left),height(node->right));
    
    int balanceFactor = getBalanceFactor(node);
    
    if (balanceFactor > 1) {
        if (key < node->left->key)
            return rightRotate(node);
        
        else if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    
    if (balanceFactor < -1) {
        if (key > node->right->key)
            return leftRotate(node);

        else if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

// Node with minimum value
Node* AVL_Tree :: nodeWithMinValue(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a Node
Node* AVL_Tree :: deleteNode(Node* root, int key) {
    // Find the node and delete it
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left,key);

    else if (key > root->key)
        root->right = deleteNode(root->right,key);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }

            else
                *root = *temp;
            free(temp);
        }

        else {
            Node* temp = nodeWithMinValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and balance the tree
    root->height = 1 + max(height(root->left),height(root->right));

    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
        if (getBalanceFactor(root->left) >= 0)
            return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(root->right) <= 0)
            return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}

// Print the tree
void AVL_Tree ::printTree(Node *root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;

        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent,false);
        printTree(root->right,indent,true);
    }
}

