#ifndef DISJOINT_ARRAYIMPLEMENTATION_DISJOINTSET_H
#define DISJOINT_ARRAYIMPLEMENTATION_DISJOINTSET_H

using namespace std;

class DisjointSet {
    public:
       int* parent;
       int* rank;
       int n;
       DisjointSet(int);
       void makeSet();
       int find(int);
       void Union(int,int);
};


#endif
