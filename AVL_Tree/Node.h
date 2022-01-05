#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

class Node {
    public:
       int key;
       Node* left;
       Node* right;
       int height;
       Node(int key);
};

#endif //AVL_TREE_NODE_H
