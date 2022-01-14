#ifndef DISJOINT_SECOND_APPROACH_DISJOINT_H
#define DISJOINT_SECOND_APPROACH_DISJOINT_H

class Disjoint {
    public:
       int* arr;
       int* size;
       int N;
       Disjoint(int);
       int root(int);
       int Union(int,int);
       int find(int,int);
       void initialize();
};

#endif //DISJOINT_SECOND_APPROACH_DISJOINT_H
