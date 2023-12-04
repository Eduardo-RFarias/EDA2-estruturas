#include "matrix-graph.h"

MatrixGraph *mgp_init(int size)
{
    MatrixGraph *gp = (MatrixGraph *)malloc(sizeof(MatrixGraph));

    gp->size = size;

    gp->adjMatrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
        gp->adjMatrix[i] = (int *)calloc(sizeof(int), size);

    return gp;
}

void mgp_free(MatrixGraph *gp)
{
    for (int i = 0; i < gp->size; i++)
        free(gp->adjMatrix[i]);
    free(gp->adjMatrix);
    free(gp);
}

void mgp_insert(MatrixGraph *gp, int origin, int destination, int weight)
{
    gp->adjMatrix[origin][destination] = weight;
    // If the graph is undirected, uncomment the line below
    // gp->adjMatrix[destination][origin] = weight;
}

int mgp_get(MatrixGraph *gp, int origin, int destination)
{
    return gp->adjMatrix[origin][destination];
}