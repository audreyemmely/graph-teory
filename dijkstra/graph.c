#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

Graph *createGraph(int numberOfVertices, int maxDegree, int isWeighted, int isDigraph)
{
    Graph *gr = (Graph*)malloc(sizeof(struct graph));

    if(gr != NULL)
    {
        int i, j;
        gr->numberOfVertices = numberOfVertices;
        gr->maxDegree = maxDegree;
        gr->isWeighted = isWeighted;
        gr->isDigraph = isDigraph;
        gr->degree = (int*)calloc(numberOfVertices, sizeof(int));
        gr->edges = (int**)malloc(numberOfVertices*sizeof(int*));

        for(i = 0; i < numberOfVertices; i++)
        {
            gr->edges[i] = (int*)malloc(maxDegree*sizeof(int));

            if(gr->isWeighted)
            {
                gr->weight = (int**)malloc(numberOfVertices*sizeof(int*));

                for (j = 0; j < numberOfVertices; j++)
                {
                    gr->weight[j] = (int*)malloc(maxDegree*sizeof(int));
                }
            }
        }
    }
}