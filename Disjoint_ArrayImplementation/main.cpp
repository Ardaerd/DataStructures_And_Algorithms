#include <iostream>
#include "DisjointSet.h"

int main() {

    DisjointSet* obj = new DisjointSet(10);

    obj->Union(2,1);
    obj->Union(4,3);
    obj->Union(8,4);
    obj->Union(9,3);
    obj->Union(6,5);
    obj->Union(5,3);

    for (int i = 0; i < obj->n; i++)
        cout << obj->parent[i] << ", ";

    cout << endl;

    if (obj->find(8) == obj->find(9))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj->find(1) == obj->find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
