#include <iostream>
#include <climits>
#include "MinHeap.h"

// Constructor: Builds a heap from a given array a[] of given size
MinHeap :: MinHeap(int cap) {
    this->heap_size = 0;
    this->capacity = cap;
    this->harr = new int[cap];
}

// Insert a new key 'k'
void MinHeap :: insertKey(int key) {
    if(heap_size == capacity) {
        cout << "\nOverflow: could not insertKey\n";
        return;
    }

    // first insert the new key at the end
    heap_size++;
    int i = heap_size-1;
    harr[i] = key;

    // fix the min heap property if it is violated
    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap ::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i],&harr[parent(i)]);
    }
}

// Method to remove min element (or root) from min heap
int MinHeap :: extractMin() {
    if (heap_size <= 0) {
        return INT_MAX;
    }

    if(heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the min value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap ::deleteKey(int i) {
    decreaseKey(i,INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// this method assumes that the subtrees are already heapified
void MinHeap ::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    if (r <heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void MinHeap :: swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int MinHeap :: parent(int i) { return (i-1)/2; }

// to get index of left child of node at index i
int MinHeap :: left(int i) { return (2*i + 1); }

// to get index of right child of node at index i
int MinHeap :: right(int i) { return (2*i + 2); }

// Returns the minimum key (key at root) from min heap
int MinHeap :: getMin() { return harr[0]; }