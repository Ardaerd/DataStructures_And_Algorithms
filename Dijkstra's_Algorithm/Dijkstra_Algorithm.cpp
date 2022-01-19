#include "Dijkstra's_Algorithm.h"

// Number of verticies in the graph


// A utility function to find the vertex with min distance value, from
// The set of verticies not yet included in shortest path tree
int Algorithm :: minDistance(int dist[], bool visited[]) {
    // initialize min value
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++)
        if (visited[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }

    return min_index;
}

// A utility function to print the constructed distance array
void Algorithm :: printSolution(int *dist) {
    cout <<"Vertex \t Distance from Source" << endl;

    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Algorithm ::dijkstra(int graph[V][V], int src) {
    int dist[V]; // the output array. dist[i] will hold the shortest distance from src to i
    bool visited[V]; // visited[i] will be true if vertex i is included in shortest path tree

    // Initialize all distance as INFINITY adn visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist,visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if is not in visited[], there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // print the constructed distance array
    printSolution(dist);
}