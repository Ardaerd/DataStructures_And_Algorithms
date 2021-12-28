#ifndef _LinkedList_
#define _LinkedList_

#include <string>
#include "Node.h"

using namespace std;

struct LinkedList {
    Node* top;
    Node* head;
    void pushNode(int);
    int end();
    int front();
    int popNode();
    string toString();
    LinkedList();
};

#endif
