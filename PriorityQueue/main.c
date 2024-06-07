#include "priorityqueue.h"
#include <stdio.h>

int maxcomp(const void* a, const void* b) {
    return (*(int*)a) > (*(int*)b);
}

void print_heap(PriorityQueue* pq) {
    for(int i = 0; i < pq->size; i++) {
        printf("%d ", pq->entries[i]);
    } printf("\n");
}

int main() {
    PriorityQueue* pq = priorityqueue_create(CUSTOM_HEAP, maxcomp);
    
    priorityqueue_insert(pq, 11);
    priorityqueue_insert(pq, -2);
    priorityqueue_insert(pq, 0);
    priorityqueue_insert(pq, 9);
    priorityqueue_insert(pq, -1);
    priorityqueue_insert(pq, 45);
    priorityqueue_insert(pq, 67);
    priorityqueue_insert(pq, 2);
    priorityqueue_insert(pq, 1);

    print_heap(pq);

    printf("%d\n", priorityqueue_pop(pq));

    print_heap(pq);

    priorityqueue_free(pq);

    return 0;
}