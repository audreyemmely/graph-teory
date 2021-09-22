#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30


struct Graph {
    int V, E;
    int edges[MAX][3];
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i){   
    if (subsets[i].parent == i)
        return i;
 
    return find(subsets, subsets[i].parent);
};

void do_union(struct subset subsets[], int v1, int v2){

    int root1 = find(subsets, v1);
    int root2 = find(subsets, v2);

    if (subsets[root1].rank < subsets[root2].rank){
        subsets[root1].parent = root2;
    }else if(subsets[root1].rank > subsets[root2].rank){        
        subsets[root2].parent = root1;}
    else{
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }

};

struct subset* create_subsets(int V){
    return (struct subset*)malloc(V * sizeof(struct subset));
};

struct subset* initialize_subsets(int V){

    struct subset* subsets = create_subsets(V);

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    return subsets;
};

int compare(const void *a, const void *b){
  int *x = (int *)a;
  int *y = (int *)b;
  
  return x[2] > y[2];
};

void kruskal(struct Graph* graph){    
    int V = graph->V;
    int j = 0;
    int i = 0;
    float mst[V-1][3];

    struct subset* subsets = initialize_subsets(V);

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);
    
    while (j < V - 1) {

        int* edge = graph->edges[i++];
 
        int x = find(subsets, edge[0]);
        int y = find(subsets, edge[1]);
 
        if (x != y) {
            mst[j][0] = edge[0];
            mst[j][1] = edge[1];
            mst[j][2] = edge[2];
            j++;
            do_union(subsets, x, y);
        }
    }
 
    int cost = 0;
    
    for (i = 0; i < j; ++i)
    {
        printf("%d -- %d == %d\n", (int) mst[i][0],(int) mst[i][1], (int) mst[i][2]);
        cost += mst[i][2];
    }
    printf("Custo: %d\n",cost);
    return;
};

int main(){
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    int V,E,v1,v2,w;

    scanf("%d %d", &V, &E);
    graph->V = V;
    graph->E = E;

    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        graph->edges[i][0]= v1;
        graph->edges[i][1] = v2;
        graph->edges[i][2] = w;
    }
 
    kruskal(graph);

    return 0;
}