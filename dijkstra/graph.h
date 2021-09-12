struct graph{
    int isWeighted;
    int isDigraph;
    int numberOfVertices;
    int maxDegree;
    int** edges;
    int** weights;
    int* degree;
};

typedef struct graph Graph;

Graph *createGraph(int numberOfVertices, int maxDegree, int isWeighted, int isDigraph);
int insertEdge(Graph* gr, int source, int target, int weight);
void graphFree(Graph *gr);
void printGraph(Graph *gr, int numberOfVertices);