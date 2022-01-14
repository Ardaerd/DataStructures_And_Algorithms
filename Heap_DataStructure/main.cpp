#include <iostream>
#include "Heap.h"

int main() {
    Heap* heap = NULL;
    vector<int> heapTree;

    heap->insert(heapTree, 3);
    heap->insert(heapTree, 4);
    heap->insert(heapTree, 9);
    heap->insert(heapTree, 5);
    heap->insert(heapTree, 2);
    heap->insert(heapTree, 7);
    heap->insert(heapTree, 6);


    cout << "Max-Heap array: ";
    heap->printArray(heapTree);

    heap->deleteNode(heapTree, 4);

    cout << "After deleting an element: ";

    heap->printArray(heapTree);
    return 0;
}
