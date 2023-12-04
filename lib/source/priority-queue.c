#include "priority-queue.h"

PriorityQueue *pq_init(int size)
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->size = 0;

    pq->heap = (int *)malloc((sizeof(int) * size) + 1);

    return pq;
}

int less(int a, int b)
{
    return a < b;
}

int pq_isEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

void pq_free(PriorityQueue *pq)
{
    free(pq->heap);
    free(pq);
}

void pq_swap(PriorityQueue *pq, int i, int j)
{
    int temp = pq->heap[i];
    pq->heap[i] = pq->heap[j];
    pq->heap[j] = temp;
}

void pq_swim(PriorityQueue *pq, int item)
{
    // While the item is not the root and is less than its parent
    while (item > 1 && less(pq->heap[PARENT(item)], pq->heap[item]))
    {
        pq_swap(pq, PARENT(item), item);
        item = PARENT(item);
    }
}

void pq_sink(PriorityQueue *pq, int item)
{
    while (LEFT(item) <= pq->size)
    {
        int child = LEFT(item);

        // If the right child is greater than the left child, use the right child
        if (child < pq->size && less(pq->heap[child], pq->heap[child + 1]))
            child++;

        // If the item is greater than the greater child, stop
        if (!less(pq->heap[item], pq->heap[child]))
            break;

        pq_swap(pq, item, child);
        item = child;
    }
}

void pq_insert(PriorityQueue *pq, int item)
{
    pq->heap[++pq->size] = item;
    pq_swim(pq, pq->size);
}

int pq_delMax(PriorityQueue *pq)
{
    int max = pq->heap[1];
    pq_swap(pq, 1, pq->size--);
    pq_sink(pq, 1);
    return max;
}