#ifndef _Hash_
#define _Hash_
#include<bits/stdc++.h>

using namespace std;

class Hash {
    public:
       int Bucket; // Number of bucket
       list<int>* table; // Pointer to an array containing buckets
       Hash(int); // Constructor
       void insertItem(int x);  // insert a key into hash table
       void deleteItem(int);    // deletes a key into hash table
       int hashFunction(int);   // hash function to map values to key
       void displayHash();
};

#endif //HASH_TABLE_HASH_H
