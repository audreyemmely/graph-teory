struct graph{
    int isWeighted;
    int isDigraph;
    int numberOfVertices;
    int maxDegree;
    int** edges;
    int** weight;
    int* degree; 
};

typedef struct graph Graph;

Graph *createGraph(int numberOfVertices, int maxDegree, int isWeighted, int isDigraph);
int removeEdge(Graph* gr, int source, int target, int isDigraph);
int addEdge(Graph* gr, int source, int target, int weight);
void freeGraph(Graph *gr);
void printGraph(Graph *gr, int numberOfVertices);