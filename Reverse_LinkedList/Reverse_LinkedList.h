#ifndef _Reverse_LinkedList_
#define _Reverse_LinkedList_

#include "Node.h"

class ReverseLinkedList {
    public:
      int size;
      Node* head;
      Node* reverseList(Node*);
      void addAtIndex(int,int);
      ReverseLinkedList();

};

#endif
