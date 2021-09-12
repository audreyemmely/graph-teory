#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph *createGraph(int numberOfVertices, int maxDegree, int isWeighted, int isDigraph){
    Graph *gr = (Graph*) malloc(sizeof(struct graph));

    if(gr != NULL){
        int i, j;
        gr->numberOfVertices = numberOfVertices;
        gr->maxDegree = maxDegree;
        gr->isWeighted = isWeighted;
        gr->isDigraph = isDigraph;

        gr->degree = (int*) calloc(numberOfVertices, sizeof(int));

        gr->edges = (int**)malloc(numberOfVertices*sizeof(int*));

        for(i = 0; i < numberOfVertices; i++){
            gr->edges[i] = (int*)malloc(maxDegree*sizeof(int));

            if(gr->isWeighted){
                gr->weights = (int**) malloc(numberOfVertices*sizeof(int*));

                for(j = 0; j < numberOfVertices; j++){
                    gr->weights[j] = (int*)malloc(maxDegree*sizeof(int));
                }
            }
        }
    }

    return gr;
}

int insertEdge(Graph* gr, int source, int target, int weight){
    if(gr == NULL) return 0;

    if(source < 0 || source >= gr->numberOfVertices) return 0;

    if(target < 0 || target >= gr->numberOfVertices) return 0;

    gr->edges[source][gr->degree[source]] = target;

    if(gr->isWeighted){
        gr->weights[source][gr->degree[source]] = weight;
    }

    gr->degree[source]++;

    if(gr->isDigraph == 0) {
        gr->edges[target][gr->degree[target]] = source;
        if(gr->isWeighted){
            gr->weights[target][gr->degree[target]] = weight;
        }
        gr->degree[target]++;
    }

    return 1;
}

void graphFree(Graph *gr){
    if(gr != NULL){
        int i;
        for(i = 0; i < gr->numberOfVertices; i++){
            free(gr->edges[i]);
        }
        free(gr->edges);

        if(gr->isWeighted){
            for(i = 0; i < gr->numberOfVertices; i++){
                free(gr->weights[i]);
            }
            free(gr->weights);
        }
        free(gr->degree);
        free(gr);
    }
}

void printGraph(Graph *gr, int numberOfVertices){
    int i, j;

    if(gr == NULL) return;

    for(i = 0; i < gr->numberOfVertices; i++){
        printf("%d -> ", i);
        
        for(j = 0; j < gr->degree[i]; j++){
            printf("%d", gr->edges[i][j]);
            if(gr->isWeighted){
                printf("[%d]", gr->weights[i][j]);
            }
            if(j + 1 < gr->degree[i]){
                printf(", ");
            }
        }
        printf("\n");
    }
}