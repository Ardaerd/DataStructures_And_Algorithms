#ifndef GRAPH_IMPLEMENTATION_GRAPH_H
#define GRAPH_IMPLEMENTATION_GRAPH_H

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    void addEdge(vector<int> adj[], int u, int v);
    void printGraph(vector<int> adj[], int v);
};

#endif //GRAPH_IMPLEMENTATION_GRAPH_H
