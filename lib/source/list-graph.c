#include "list-graph.h"

ListGraph *lgp_init(int size)
{
    ListGraph *gp = (ListGraph *)malloc(sizeof(ListGraph));
    gp->size = size;
    gp->adjList = (GraphNode **)calloc(sizeof(GraphNode *), size);
    return gp;
}

void lgp_free(ListGraph *gp)
{
    for (int i = 0; i < gp->size; i++)
    {
        GraphNode *node = gp->adjList[i];
        while (node != NULL)
        {
            GraphNode *aux = node;
            node = node->next;
            free(aux);
        }
    }

    free(gp->adjList);
    free(gp);
}

void lgp_insert(ListGraph *gp, int origin, int destination, int weight)
{
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->value = destination;
    node->weight = weight;

    GraphNode *aux = gp->adjList[origin];
    gp->adjList[origin] = node;
    node->next = aux;

    // If the graph is undirected, uncomment the following lines
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->value = origin;
    node->weight = weight;

    aux = gp->adjList[destination];
    gp->adjList[destination] = node;
    node->next = aux;
}

int lgp_get(ListGraph *gp, int origin, int destination)
{
    GraphNode *node = gp->adjList[origin];

    while (node != NULL)
    {
        if (node->value == destination)
            return node->weight;

        node = node->next;
    }

    return 0;
}