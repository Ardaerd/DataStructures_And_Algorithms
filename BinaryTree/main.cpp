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
    root = root->insert(root,5);
    root = root->insert(root,11);

    cout << "Root: " << root->data << endl;

    //root->Delete(root,10);

    int num;
    cout << "Enter the number you wanna check: ";
    cin >> num;

    if(root->search(root,num) != NULL)
        cout << num << " is exist in our binary tree" << endl;
    else
        cout << num << " is not exist in our binary tree" << endl;

    cout << "Min element in the tree: " << root->findMin(root)->data << endl;
    cout << "Max element in the tree: " << root->findMax(root)->data << endl;
    cout << "Height of the tree is: " << root->findHeight(root) << endl;

    cout << "Is this tree is a binary tree: " << root->IsBinarySearchTree(root) << endl;
    cout << "For second check implementation: " << root->IsBstUtil(root,root->findMin(root)->data,root->findMax(root)->data) << endl; // This is not working

    int child;
    cout << "Enter a number: ";
    cin >> child;

    cout << "Successor of " << child << ": " << root->Getsuccessor(root,child)->data << endl;

    return 0;
}
