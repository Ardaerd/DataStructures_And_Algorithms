#ifndef GRAPH_IMPLEMENTATION_GRAPH_H
#define GRAPH_IMPLEMENTATION_GRAPH_H

#include <list>
#include <stack>

using namespace std;

class Graph {
    public:
       int vertices;  // No of the verticies
       list<int>* adjacent;  // Pointer to an array containing adjacency listsList
       void topologicalSortUtil(int vertices,bool visited[],stack<int> Stack);  // A function used by topologicalSort
       Graph(int vertices); // Constructor
       void addEdge(int v, int w);  // Function to add an edge to graph
       void topologicalSort(); // Prints a topological sort of the complete graph
};

#endif //GRAPH_IMPLEMENTATION_GRAPH_H
