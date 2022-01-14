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

// Preorder Traversal
void BST :: preorder(Node* root) {

    if (root != NULL) {
        // Traverse root
        cout << root->data << "->";

        // Traverse left
        preorder(root->left);

        // Traverse right
        preorder(root->right);
    }
}

// Postorder traversal
void BST :: postorder(Node* root) {
    if (root != NULL) {
        // Traverse left
        postorder(root->left);

        // Traverse right
        postorder(root->right);

        // Traverse root
        cout << root->data << "->";
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

bool BST :: isFullBinaryTree(Node* root) {
    // Checking for emptiness
    if (root == NULL)
        return true;

    // Checking for the presence of children
    if (root->left == NULL && root->right == NULL)
        return true;

    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

    return false;
}

int BST :: depth(Node* node) {
    int depth = 0;

    while (node != NULL) {
        depth++;
        node = node->left;
    }

    return depth;
}

bool BST ::isPerfectBinaryTree(Node *root, int depth, int level) {
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return depth == (level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return isPerfectBinaryTree(root->left, depth, level + 1) && isPerfectBinaryTree(root->right, depth, level + 1);
}

bool BST ::isPerfect(Node* root) {
    int d = depth(root);

    return isPerfectBinaryTree(root,d,0);
}

// Count the number of nodes
int BST ::countNumNode(Node *root) {
    if (root == NULL)
        return 0;

    return (1 + countNumNode(root->left) + countNumNode(root->right));
}

// Check if the tree is a complete binary tree
bool BST ::checkComplete(Node *root, int index, int numberNodes) {
    // check if the tree is empty
    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

/* Returns true if binary tree
with root as root is height-balanced */
bool BST :: isBalanced(Node* root) {
    int lh; // for height of left subtree
    int rh; // for height of right subtree

    // If tree is empty then return true
    if (root == NULL)
        return 1;

    // Get the height of left and right sub trees
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    // If reach the end then tree is not height balanced
    return 0;
}

// The function compute the height of a tree. Height is the number of nodes
// along the longest path from the root node down to the farthest leaf node.
int BST :: height(Node* node) {
    // base case tree is empty
    if (node == NULL)
        return 0;

    // If tree is not empty then height = 1 max of the left height and right heights
    return 1 + max(height(node->left),height(node->right));

}