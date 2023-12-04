#include <stdio.h>
#include "list-graph.h"
#include "stack.h"
#include "hash-table.h"

void dfs(ListGraph *gp)
{
    HashTable *visited = ht_init(gp->size, 0);
    Stack *stack = stack_init(gp->size);

    for (int vertex = 0; vertex < gp->size; vertex++)
    {
        // If vertex not visited
        if (!ht_get(visited, vertex))
        {
            stack_push(stack, vertex);
            ht_insert(visited, vertex, 1);

            while (!stack_empty(stack))
            {
                int current = stack_pop(stack);
                printf("%d ", current);

                GraphNode *node = gp->adjList[current];

                // For each neighbor of current
                while (node != NULL)
                {
                    // If neighbor not visited
                    if (!ht_get(visited, node->value))
                    {
                        stack_push(stack, node->value);
                        ht_insert(visited, node->value, 1);
                    }
                    node = node->next;
                }
            }

            printf("\n");
        }
    }

    ht_free(visited);
    stack_free(stack);
}

int main()
{
    ListGraph *gp = lgp_init(8);

    lgp_insert(gp, 1, 4, 1);
    lgp_insert(gp, 1, 2, 1);
    lgp_insert(gp, 1, 5, 1);
    lgp_insert(gp, 2, 4, 1);
    lgp_insert(gp, 3, 7, 1);
    lgp_insert(gp, 4, 5, 1);
    lgp_insert(gp, 6, 2, 1);

    dfs(gp);

    lgp_free(gp);

    return 0;
}