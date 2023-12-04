#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <stdlib.h>

typedef struct
{
    int **adjMatrix;
    int size;
} MatrixGraph;

MatrixGraph *mgp_init(int size);

void mgp_free(MatrixGraph *gp);

void mgp_insert(MatrixGraph *gp, int origin, int destination, int weight);

int mgp_get(MatrixGraph *gp, int origin, int destination);

#endif // MATRIX_GRAPH_H