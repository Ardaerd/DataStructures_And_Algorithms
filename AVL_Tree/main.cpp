#include <iostream>
#include "AVL_Tree.h"

int main() {
    AVL_Tree* tree = new AVL_Tree();
    Node* root = NULL;
    root = tree->insertNode(root,33);
    root = tree->insertNode(root,13);
    root = tree->insertNode(root,53);
    root = tree->insertNode(root,9);
    root = tree->insertNode(root,21);
    root = tree->insertNode(root,61);
    root = tree->insertNode(root,8);
    root = tree->insertNode(root,11);
    tree->printTree(root,"", true);
    root = tree->deleteNode(root,13);
    cout << "After deleting" << endl;
    tree->printTree(root,"",true);

    return 0;
}
