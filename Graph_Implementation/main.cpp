#include <iostream>
#include "Graph.h"

int main() {
    int V = 5;
    vector<int> adj[V];
    Graph* g = new Graph();
    g->addEdge(adj,0,1);
    g->addEdge(adj,0,4);
    g->addEdge(adj,1,2);
    g->addEdge(adj,1,3);
    g->addEdge(adj,1,4);
    g->addEdge(adj,2,3);
    g->addEdge(adj,3,4);

    g->printGraph(adj,V);

    return 0;
}
