#ifndef _Node_
#define _Node_

#include <iostream>
#include <clocale>

using namespace std;

class Node {
    public:
       int data;
       Node* left;
       Node* right;
       Node(int);
};

#endif
