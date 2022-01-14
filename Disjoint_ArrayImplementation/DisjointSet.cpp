#include <iostream>
#include "DisjointSet.h"

DisjointSet :: DisjointSet (int n) {
    parent = new int[n];
    rank = new int[n];
    this->n = n;
    makeSet();
}

// Creates n single item sets
void DisjointSet :: makeSet() {

    for (int i = 0; i < n; i++)
        parent[i] = i;

}

// Finds set of given item x
int DisjointSet :: find (int x) {
    // Finds the representative of the set
    // that x is an element of

    // If x is not the parent of itself
    // Then x is not the representative of his set

    if (parent[x] != x)
        parent[x] = find(parent[x]);

    // so we recursively call find on its parent and move i's node
    // directly under the representative of this set

    return parent[x];
}

// Do union of two sets represented by x and y
void DisjointSet :: Union(int x, int y) {
    // find current sets of x and y
    int x_set = find(x);
    int y_set = find(y);

    // If they are already in the same set
    if (x_set == y_set) {
        cout << "X and Y already in the same set" << endl;
        return;
    }

   // Put smaller ranked item under
   // bigger ranked item if ranks are different
   if (rank[x_set] < rank[y_set])
       parent[x_set] = y_set;

   else if (rank[x_set] > rank[y_set])
       parent[y_set] = x_set;

   // If ranks are same, then increment rank
   else {
       parent[y_set] = x_set;
       rank[x_set]++;
   }

}