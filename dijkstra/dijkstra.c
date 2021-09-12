#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

void dijkstra(Graph *gr, int ini, int *prev, int *dist){
    int i, count, nv, ind, *visited, u;

    count = nv = gr->numberOfVertices;

    visited = (int*) malloc(nv * sizeof(int));

    for(i = 0; i < nv; i++){
        prev[i] = -1;
        dist[i] = -1;
        visited[i] = 0;
    }

    dist[ini] = 0;

    while(count > 0){
        u = searchMinDist(dist, visited, nv);

        if(u == -1){
            break;
        }

        visited[u] = 1;
        count--;

        for(i = 0; i < gr->degree[u]; i++){
            ind = gr->edges[u][i];
            if(dist[ind] < 0){
                dist[ind] = dist[u] + gr->weights[u][i];

                prev[ind] = u;
            }else{
                if(dist[ind] > dist[u] + gr->weights[u][i]){
                    dist[ind] = dist[u] + gr->weights[u][i];

                    prev[ind] = u;
                }
            }
        }
    }

    free(visited);
}

int searchMinDist(int *dist, int *visited, int nv){
    int i, min = -1, first = 1;
    for(i = 0; i < nv; i++){
        if(dist[i] >= 0 && visited[i] == 0){
            if(first){
                min = i;
                first = 0;
            }else{
                if(dist[min] > dist[i]){
                    min = i;
                }
            }
        }
    }

    return min;
}

int findPath(int source, int target, int nVertices, int *path, int *prev, int count) {
    int i;
    for(i = 0; i < nVertices; i++){
        path[i] = -1;
    }

    while(target != source) {
        if(count < 0 || target < 0) {
            printf("Nao existe caminho\n");
            return 0;
        }
        path[count] = target;
        target = prev[target];
        count--;
    }

    return 1;
}

void printPath(int source, int nVertices, int *path) {
    int i;
    printf("%d ->", source);
    for(i = 0; i < nVertices; i++){
        if(path[i] != -1){
            printf(" %d", path[i]);
            if(i + 1 != nVertices){
                printf(" ->");   
            }
        }
    }
    printf("\n");
}