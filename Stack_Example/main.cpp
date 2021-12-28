#include <iostream>
#include "LinkedList.h";


int main() {

    LinkedList* stack = new LinkedList();

    stack->pushNode(1);
    stack->pushNode(2);
    stack->pushNode(3);
    stack->popNode();

    cout << stack->end() << endl;
    cout << stack->front() << endl;

    cout << stack->toString() << endl;

    return 0;
}
