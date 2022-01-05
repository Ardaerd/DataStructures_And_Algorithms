#ifndef _Node_
#define _Node_

class Node {
    public:
       int key;
       Node* left;
       Node* right;
       int height;
       Node(int key);
};

#endif //AVL_TREE_NODE_H
