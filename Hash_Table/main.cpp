#include <iostream>
#include "Hash.h"

int main() {

    // array that contains keys to be mapped
    int a[] = {15,11,27,8,12};
    int n = sizeof(a) / sizeof(a[0]);
    cout << sizeof(a[0]) << " " << n << " " << sizeof(a) << endl;

    // insert the keys into the hash table
    Hash h(7);   // 7 is count of buckets in hash table

    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // delete 12 from hash table
    h.deleteItem(12);

    // display the hash table
    h.displayHash();

    return 0;
}
