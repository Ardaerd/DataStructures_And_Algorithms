#include <iostream>
#include "Heap.h"

void Heap :: swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heap :: heapify(vector<int> &ht, int i) {
    int size = ht.size();
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && ht[left] > ht[largest])
        largest = left;

    if (right < size && ht[right] > ht[largest])
        largest = right;

    if (largest != i) {
        swap(&ht[i], &ht[largest]);
        heapify(ht,largest);
    }
}

void Heap :: insert(vector<int> &ht, int newNum) {
    int size = ht.size();

    if (size == 0)
        ht.push_back(newNum);

    else {
        ht.push_back(newNum);
        for (int i = size/2 - 1; i >= 0; i--)
            heapify(ht,i);
    }
}

void Heap ::deleteNode(vector<int> &ht, int num) {
    int size = ht.size();
    int i;

    for (i = 0; i < size; i++) {
        if (num == ht[i])
            break;
    }

    swap(&ht[i],&ht[size-1]);
    ht.pop_back();

    for (int i = size/2 - 1; i>= 0; i--)
        heapify(ht,i);
}

void Heap :: printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}