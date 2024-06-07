#pragma once

typedef int (*Comparator)(const void* a, const void* b);

typedef enum PriorityQueueFlags{
    MIN_HEAP = (1 << 0),
    MAX_HEAP = (1 << 1),
    CUSTOM_HEAP = (1 << 2)
} PriorityQueueFlags;

typedef struct PriorityQueue {
    int *entries;
    int size;
    int capacity;
    PriorityQueueFlags type;
    Comparator comp;
} PriorityQueue;

PriorityQueue* priorityqueue_create(PriorityQueueFlags, ...);

void priorityqueue_insert(PriorityQueue*, int);
int priorityqueue_pop(PriorityQueue*);
int priorityqueue_peek(PriorityQueue*);

void priorityqueue_free(PriorityQueue*);