#include "graph.h"

void dijkstra(Graph *gr, int ini, int *prev, int *dist);
int searchMinDist(int *dist, int *visited, int nv);
int findPath(int source, int target, int nVertices, int *path, int *prev, int count);
void printPath(int source, int nVertices, int *path);