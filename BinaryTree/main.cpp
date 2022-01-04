#include <iostream>
#include "BST_Node.h"

int main() {
    BST_Node* root = NULL;  // Creating an empty tree
    root = root->insert(root,15);
    root = root->insert(root,10);
    root = root->insert(root,20);
    root = root->insert(root,25);
    root = root->insert(root,8);
    root = root->insert(root,12);
    root = root->insert(root,18);

    cout << "Root: " << root->data << endl;

    int num;
    cout << "Enter the number you wanna check: ";
    cin >> num;

    if(root->search(root,num))
        cout << num << " is exist in our binary tree" << endl;
    else
        cout << num << " is not exist in our binary tree" << endl;

    cout << "Min element in the tree: " << root->findMin(root);

    return 0;
}
