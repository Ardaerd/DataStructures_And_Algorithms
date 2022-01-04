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

BST_Node* BST_Node :: search(BST_Node* root,int data) {
    if (root == NULL)
        return NULL;

    else if (root->data == data)
        return root;

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

BST_Node* BST_Node :: findMax(BST_Node *root) {
    if (root == NULL) {
        cout << "WARNING: Tree is empty!" << endl;
        return NULL;
    }

    BST_Node* current = root;

    while (current->right != NULL)
        current = current->right;

    return current;
}

BST_Node* BST_Node :: findMin(BST_Node* root) {
    if (root == NULL) {
        cout << "WARNING: Tree is empty!" << endl;
        return NULL;
    }

    BST_Node* current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
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

BST_Node* BST_Node :: Delete(BST_Node* root,int data) {
    if (root == NULL)
        return root;

    else if (data < root->data)
        root->left = Delete(root->left,data);

    else if (data > root->data)
        root->right = Delete(root->right,data);

    // Wohoooo.... I found you, Get ready to delete
    else {
        // Case 1: No child
        if ((root->left == NULL) && (root->right == NULL)) {
            delete root;
            root = NULL;
            return root;
        }

        // Case 2: One Child
        else if (root->left == NULL) {
            BST_Node* temp = root;

            root = root->right;
            delete temp;
            cout << "New root: " << root->data << endl;
            return root;
        }

        else if (root->right == NULL) {
            BST_Node* temp = root;

            root = root->left;
            delete temp;
            cout << "New root: " << root->data << endl;
            return root;
        }

        // Case 3: 2 Children
        else {
            BST_Node* temp = findMin(root->right);

            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }

        cout << "New root: " << root->data << endl;
        return root;
    }
}

// Function to find Inorder Successor in a BST
BST_Node* BST_Node :: Getsuccessor(BST_Node *root, int data) {
    // Search the Node - O(h)
    BST_Node* current = search(root,data);

    if (current == NULL)
        return NULL;

    // Case 1: Node has right subtree
    if (current->right != NULL)
        return findMin(current->right); // O(h)

    // Case 2: No right subtree - O(h)
    else {
        BST_Node* successor = NULL;
        BST_Node* ancestor = root;

        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        return successor;
    }
}