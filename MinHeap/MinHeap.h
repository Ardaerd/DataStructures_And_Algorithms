//
// Created by arda on 1/6/2022.
//

#ifndef MINHEAP_MINHEAP_H
#define MINHEAP_MINHEAP_H

using namespace std;

class MinHeap {
    public:
       int* harr; // pointer to array elemnets in heap
       int capacity; // maximum possible size of min heap
       int heap_size; // current number of elements in min heap
       MinHeap(int capacity); // constructor
       void MinHeapify(int); // to heapify a subtree with the root at given index
       void swap(int* x,int* y); // Prototype of utility function to swap two integers
       int parent(int);
       int left(int);
       int right(int);
       int extractMin(); // to extract the root which is the min element
       void decreaseKey(int,int); // Decreases key value of key at index i to new_val
       int getMin(); // Returns the min key (key root) from min heap
       void deleteKey(int); // Deletes a key sorted at index i
       void insertKey(int); // Inserts a new key 'k'

};

#endif //MINHEAP_MINHEAP_H
