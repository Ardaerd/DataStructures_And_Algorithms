#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BST* tree = NULL;
    struct Node *root = NULL;
    root = tree->insert(root, 8);
    root = tree->insert(root, 3);
    root = tree->insert(root, 1);
    root = tree->insert(root, 6);
    root = tree->insert(root, 7);
    root = tree->insert(root, 10);
    root = tree->insert(root, 14);
    root = tree->insert(root, 4);

    cout << root->data << endl;

    cout << "Inorder traversal: ";
    tree->inorder(root);

    cout << "\nAfter deleting 10\n";
    root = tree->deleteNode(root, 10);
    cout << "Inorder traversal: ";
    tree->inorder(root);
    return 0;
}
