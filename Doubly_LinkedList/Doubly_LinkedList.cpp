#include "Doubly_LinkedList.h"

Doubly_LinkedList :: Doubly_LinkedList() {
    this->front = NULL;
    this->end = NULL;
}

void Doubly_LinkedList :: add_front (int data) {
    // Creating new node
    Node* temp = new Node(data);
    temp->prev = NULL;
    temp->next = front;

    // List is empty
    if (front == NULL)
        end = temp;
    else
        front->prev = temp;

    front = temp;
}

void Doubly_LinkedList ::add_before(Node* n, int data) {
    Node* temp = new Node(data);
    temp->next = n;
    temp->prev = n->prev;
    n->prev = temp;

    // if node is to be inserted before first node
    if (n->prev == NULL)
        front = temp;
}

void Doubly_LinkedList ::add_after (Node* n, int data) {
    Node* temp = new Node(data);
    temp->prev = n;
    temp->next = n->next;
    n->next = temp;

    // if node is to be inserted after last node
    if (n->next == NULL)
        end = temp;
}

void Doubly_LinkedList :: add_end(int data) {
    // create new node
    Node* temp = new Node(data);
    temp->prev = end;
    temp->next = NULL;

    // if list is empty
    if (end == NULL)
        front = temp;
    else
        end->next = temp;
    end = temp;
}

void Doubly_LinkedList :: delete_node(Node* n) {
    // if node to be deleted is first node of the list
    if (n->prev == NULL) {
        front = n->next;  // the next node will be front of list
        front->prev = NULL;
    }

    // if node to be deleted is  last node of list
    else if (n->next == NULL) {
        end = n->prev;          // the previous node will be last of list
        end->next = NULL;
    }

    else {
        // previous node's next will point to current node's next
        n->prev->next = n->next;
        // next node's prev will point to current node's prev
        n->next->prev = n->prev;
    }
}

void Doubly_LinkedList ::forward_traverse() {
    Node* trav;
    trav = front;

    while (trav != NULL) {
        cout << trav->data <<endl;
        trav = trav->next;
    }
}

void Doubly_LinkedList :: backward_traverse()
{
    Node* trav;
    trav = end;
    while(trav != NULL)
    {
        cout<<trav->data<<endl;
        trav = trav->prev;
    }
}

string Doubly_LinkedList ::toString() {
    string list = "[";
    Node* checker = this->front;

    while (checker->next != NULL) {
        list += to_string(checker->data) + ", ";
        checker = checker->next;
    }
    list+= to_string(checker->data) + "]";
    return list;
}



