#pragma once
#include <stddef.h>

typedef struct Vector {
  int item_size;
  void *items;
  size_t size;
  size_t capacity;
} Vector;

Vector *vector_init(int item_size);

void vector_push(Vector *vector, void *item);
void vector_push_front(Vector *vector, void *item);

void *vector_pop(Vector *vector);
void *vector_pop_front(Vector *vector);

void *vector_get(Vector *vector, int index);
void *vector_front(Vector *vector);
void *vector_end(Vector *vector);

void vector_sort(Vector *vector, int (*comparator)(const void *, const void *));

void vector_free(Vector *vector);
