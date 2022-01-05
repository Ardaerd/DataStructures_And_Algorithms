#include "Hash.h"

// hash function to map values to key
int Hash :: hashFunction(int x) {
    return (x % Bucket);
}

Hash :: Hash(int size) {
    this->Bucket = size;
    this->table = new list<int>[Bucket];
}

void Hash :: insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash :: deleteItem(int key) {
    // Get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

void Hash :: displayHash() {
    for (int i = 0; i < Bucket; i++) {
        cout << i;
        for (auto x : table[i])
            cout << "-->" << x;
        cout << endl;
    }
}