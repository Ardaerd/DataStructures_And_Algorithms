#include "Graph.h"


// A utility function to add an edge in an undirected graph.
void Graph :: addEdge(vector<int> adj[],int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list representation of graph
void Graph :: printGraph(vector<int> adj[],int v) {
    for (int i = 0; i < v; ++i) {
        cout << "\n Adjacency list of vertex " << v << "\n head ";

        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}