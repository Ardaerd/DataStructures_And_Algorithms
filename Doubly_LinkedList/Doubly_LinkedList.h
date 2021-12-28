#ifndef _Doubly_LinkedList_
#define _Doubly_LinkedList_

#include "Node.h"
#include <clocale>
#include <iostream>

using namespace std;

class Doubly_LinkedList {
    public:
       Node* front;  // points to first node of list
       Node* end;    // points to last node of list
       void add_front(int);
       void add_after(Node*,int);
       void add_before(Node*,int);
       void add_end(int);
       void delete_node(Node*);
       void forward_traverse();
       void backward_traverse();
       string toString();
       Doubly_LinkedList();

};

#endif
