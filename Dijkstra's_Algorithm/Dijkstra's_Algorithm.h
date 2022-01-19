#ifndef DIJKSTRA_S_ALGORITHM_DIJKSTRA_S_ALGORITHM_H
#define DIJKSTRA_S_ALGORITHM_DIJKSTRA_S_ALGORITHM_H

#include <climits>
#include <iostream>

using namespace std;

#define V 9

class Algorithm {
    public:
      int minDistance(int dist[], bool visited[]);
      void printSolution(int dist[]);
      void dijkstra(int graph[][V],int src);

};

#endif //DIJKSTRA_S_ALGORITHM_DIJKSTRA_S_ALGORITHM_H
