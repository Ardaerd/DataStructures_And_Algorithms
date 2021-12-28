#ifndef _Node_
#define _Node_

struct Node {
    int data;
    struct Node* nextLink;
    struct Node* prev;
    Node(int);
};

#endif