#ifndef HEAP_DATASTRUCTURE_HEAP_H
#define HEAP_DATASTRUCTURE_HEAP_H

#include "vector"

using namespace std;

class Heap {
    public:
       void swap(int* a, int* b);
       void heapify(vector<int> &ht, int i);
       void insert(vector<int> &ht, int newNum);
       void deleteNode(vector<int> &ht, int num);
       void printArray(vector<int> &ht);
};

#endif //HEAP_DATASTRUCTURE_HEAP_H
