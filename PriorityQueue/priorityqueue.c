#include "priorityqueue.h"
#include <stdlib.h>
#include <stdarg.h>

#define INITIAL_CAPACITY 1000

int max_heap_comparator(const void* a, const void* b) { return (*(int*)a) > (*(int*)b); }
int min_heap_comparator(const void* a, const void* b) { return (*(int*)a) < (*(int*)b); }

PriorityQueue* priorityqueue_create(PriorityQueueFlags type, ...) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if(!pq) exit(EXIT_FAILURE);

    pq->capacity = INITIAL_CAPACITY;

    pq->entries = (int*)malloc(sizeof(int) * pq->capacity);
    if(!pq->entries) exit(EXIT_FAILURE);
    
    pq->size = 0;
    pq->type = type;

    va_list args;
    va_start(args, type);

    switch (pq->type) {
        case MIN_HEAP:
            pq->comp = min_heap_comparator;
            break;
        case CUSTOM_HEAP:
            pq->comp = va_arg(args, Comparator);
            break;
        default:
            pq->comp= max_heap_comparator;
            break;
    }

    va_end(args);

    return pq;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void priorityqueue_heapify_up(PriorityQueue* pq) {
    int child = pq->size-1;
    int parent = (pq->size-2)/2;
    
    do {
        if(pq->comp(&pq->entries[child], &pq->entries[parent])) {
            swap(&pq->entries[parent], &pq->entries[child]);

            child = parent;
            parent = (parent-1)/2;
            continue;
        }
        break;
    } while(child);
}

void priorityqueue_heapify_down(PriorityQueue* pq) {
    swap(&pq->entries[0], &pq->entries[pq->size]);

    int parent = 0;
    int left_child = (parent*2)+1;
    int right_child = left_child+1;

    do {
        if(pq->comp(&pq->entries[left_child], &pq->entries[parent]) || pq->comp(&pq->entries[left_child], &pq->entries[parent])) {
            int child_to_be_swapped = pq->comp(&pq->entries[left_child], &pq->entries[right_child]) ? left_child : right_child;
            swap(&pq->entries[child_to_be_swapped], &pq->entries[parent]);

            parent = child_to_be_swapped;
            left_child = (parent*2)+1;
            right_child = left_child+1;
            continue;
        }
        break;
    } while(
        (left_child < pq->size)
    );
    
}

void priorityqueue_insert(PriorityQueue* pq, int val) {
    pq->entries[pq->size++] = val;
    priorityqueue_heapify_up(pq);
}

int priorityqueue_pop(PriorityQueue* pq) {
    if(pq->size == 0) exit(EXIT_FAILURE);
    int top = pq->entries[0];

    --pq->size;
    priorityqueue_heapify_down(pq);

    return top;
}

int priorityqueue_peek(PriorityQueue* pq) {
    if(pq->size == 0) exit(EXIT_FAILURE);
    return pq->entries[0];
}

void priorityqueue_free(PriorityQueue* pq) {
    free(pq->entries);
    free(pq);
}