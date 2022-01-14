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
    root = tree->insert(root, 9);
    root = tree->insert(root, 12);
    root = tree->insert(root, 14);
    root = tree->insert(root, 4);
    root = tree->insert(root, 15);
    root = tree->insert(root, 17);
    root = tree->insert(root, 19);



    cout << "Root: " << root->data << endl;

    cout << "Inorder traversal: ";
    tree->inorder(root);

    cout << "\nAfter deleting 10, 4, and 7\n";
    root = tree->deleteNode(root, 10);
    root = tree->deleteNode(root,4);
    root = tree->deleteNode(root,7);
    root = tree->deleteNode(root,14);


    cout << "Inorder traversal: ";
    tree->inorder(root);

    cout << "\nPreorder Traversal: ";
    tree->preorder(root);

    cout << "\nPostorder Traversal: ";
    tree->postorder(root);

    cout << "\n---------  Full Binary Tree  ---------" << endl;
    cout << "(Every parent node/internal node has either two or no children.)";

    if (tree->isFullBinaryTree(root))
        cout << "\nFull Binary Tree: "<<  "True\n";
    else
        cout << "\nFull Binary Tree: " << "False\n";

    cout << "\n---------  Perfect Binary Tree  ---------" << endl;
    cout << "(if both of its subtrees are of height h - 1 and are non-overlapping.)";

    if (tree->isPerfect(root))
        cout << "\nPerfect Binary Tree: True\n";
    else
        cout << "\nPerfect Binary Tree: False\n";

    cout << "\n---------  Complete Binary Tree  ---------" << endl;
    cout << "(All the leaf elements must lean towards the left.)";
    if (tree->checkComplete(root, 0, tree->countNumNode(root)))
        cout << "\nComplete Binary Tree: True\n";
    else
        cout << "\nComplete Binary Tree: False\n";


    cout << "\n---------  Balanced Binary Tree  ---------" << endl;
    cout << "(Difference between the left and the right subtree for any node is not more than one.)";
    if (tree->isBalanced(root))
        cout << "\nThe tree is balanced";
    else
        cout << "\nThe tree is not balanced";

    return 0;
}
