#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include <stdlib.h>

typedef struct graph_node
{
    int value;
    int weight;
    struct graph_node *next;
} GraphNode;

typedef struct
{
    GraphNode **adjList;
    int size;
} ListGraph;

ListGraph *lgp_init(int size);

void lgp_free(ListGraph *gp);

void lgp_insert(ListGraph *gp, int origin, int destination, int weight);

int lgp_get(ListGraph *gp, int origin, int destination);

#endif // LIST_GRAPH_H