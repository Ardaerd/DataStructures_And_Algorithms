#include <iostream>
#include "Graph.h"


Graph :: Graph(int vertices) {
    this->vertices = vertices;
    adjacent = new list<int>[vertices];
}

void Graph :: addEdge(int v, int w) {
    adjacent[v].push_back(w); // Add w to v's list.
}

void Graph ::topologicalSortUtil(int vertices, bool *visited, stack<int> Stack) {
    // Mark the current node as visited
    visited[vertices] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int> :: iterator i;
    for (i = adjacent[vertices].begin(); i != adjacent[vertices].end(); ++i) {
        if (!visited[*i])
            topologicalSortUtil(*i,visited,Stack);
    }

    // Push current vertex to stack which stores result
    Stack.push(vertices);
}

// The function to do topological sort It uses recursive topologicalSortUtil()
void Graph ::topologicalSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        if (visited[i] == false)
            topologicalSortUtil(i,visited,Stack);
    }

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}