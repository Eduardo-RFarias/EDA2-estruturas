#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdlib.h>

#define PARENT(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) (((x) << 1) + 1)

// Priority queue represented by a max heap.
//
// For a min heap, invert the less function.
//
// The first element is in the index 1 (0 is not used)
// The parent of the element in the index k is in the index k/2
// The left child of the element in the index k is in the index 2k
// The right child of the element in the index k is in the index 2k+1
typedef struct
{
    int size;
    int *heap;
} PriorityQueue;

PriorityQueue *pq_init(int size);

int pq_isEmpty(PriorityQueue *pq);

void pq_free(PriorityQueue *pq);

void pq_insert(PriorityQueue *pq, int item);

int pq_delMax(PriorityQueue *pq);

#endif // PRIORITY_QUEUE_H