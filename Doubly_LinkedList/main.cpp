#include <iostream>
#include "Doubly_LinkedList.h"

using namespace std;

int main() {

    Doubly_LinkedList* list = new Doubly_LinkedList();
    list->add_front(1);
    list->add_end(5);
    list->add_after(list->front,2);
    list->add_after(list->front,3);
    list->add_before(list->end,4);

    cout << list->toString() << endl;

    return 0;
}
