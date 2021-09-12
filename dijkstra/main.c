#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

void inputError();

int main() {
    int numberVertices, maximumDegree, numberEdges, isDigraph;
    scanf("%d %d %d %d", &numberVertices, &maximumDegree, &numberEdges, &isDigraph);

    // para dijkstra, assumimos que o graph é ponderado
    Graph *gr = createGraph(numberVertices, maximumDegree, 1, isDigraph);

    int source, target;
    scanf("%d %d", &source, &target);

    if(source < 0 || source >= numberVertices || target < 0 || target >= numberVertices) {
        inputError();
    }

    int i, v1, v2, weight;
    for(i = 0; i < numberEdges; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        if(v1 < 0 || v1 >= numberVertices || v2 < 0 || v2 >= numberVertices) {
            inputError();
        }
        insertEdge(gr, v1, v2, weight);
    }

    int prev[numberVertices];
    int dist[numberVertices];
    int path[numberVertices];
    int counter = numberVertices - 1;

    for(i = 0; i < numberVertices; i++){
        prev[i] = -1;
    }

    dijkstra(gr, source, prev, dist);

    int found = findPath(source, target, numberVertices, path, prev, counter);
    
    if(found) {
        printPath(source, numberVertices, path);
    }

    graphFree(gr);

    return 0;
}

void inputError() {
    printf("Erro nos valores de entrada\n");
    printf("Vértice está fora dos limites de 0 a n - 1\n");
    exit(-1);
}