#include "Disjoint.h"

Disjoint :: Disjoint(int N) {
    this->N = N;
    this->arr = new int[N];
    this->size = new int[N];

    initialize();
}

// modified initialize function
void Disjoint :: initialize() {
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        size[i] = 1;
    }
}


// finding root of an element
int Disjoint :: root(int i) {
    while (arr[i] != i)
        i = arr[i];

    return i;
}

// modified union function where we connect the elements by changing the root of one of the elements
int Disjoint :: Union (int x, int y) {
    int root_X = root(x);
    int root_Y = root(y);

    arr[root_X] = root_Y;  // Setting parent of root(X) as root(Y)
}

int  Disjoint ::find (int x, int y) {
    // If X and Y have the same root, it means that they are connected.
    if (root(x) == root(y))
        return true;
    else
        return false;
}


