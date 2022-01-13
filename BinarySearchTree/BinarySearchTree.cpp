#include "BinarySearchTree.h"

// Create a node
Node* BST :: newNode(int data) {
    Node* newNode = new Node(data);
    return newNode;
}

// Inorder Traversal
void BST :: inorder(Node *root) {
    if (root != NULL) {
        // Traverse left
        inorder(root->left);

        // Traverse root
        cout << root->data << "->";

        // Traverse right
        inorder(root->right);
    }
}

Node* BST :: insert(Node* root, int data) {
    // Return a new node if the tree is empty
    if (root == NULL)
        return newNode(data);

    // Traverse to the right place and insert the node
    if (data < root->data)
        root->left  = insert(root->left,data);
    else
        root->right  = insert(root->right,data);

    return root;
}

// Find the inorder successor
Node* BST ::minValueNode(Node *root) {
    Node* current = root;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
Node* BST :: deleteNode(Node* root, int data) {
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left,data);
    else if (data > root->data)
        root->right = deleteNode(root->right,data);

    // You find the node
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        Node* temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}