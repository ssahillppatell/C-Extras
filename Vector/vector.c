#include "vector.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 256

// TODO: Memory Allocation failure handling
Vector *vector_init(int item_size) {
  Vector *v = malloc(sizeof(Vector));

  v->item_size = item_size;
  v->size = 0;
  v->capacity = INITIAL_CAPACITY;
  v->items = malloc(v->capacity * item_size);

  return v;
}

void vector_push(Vector *v, void *item) {
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->items = realloc(v->items, v->capacity * v->item_size);
  }
  memcpy((char *)v->items + v->size * v->item_size, item, v->item_size);
  v->size++;
}

void *vector_get(Vector *v, int index) {
  return (char *)v->items + index * v->item_size;
}

void vector_free(Vector *v) {
  for (int i = 0; i < v->size; i++) {
    free(vector_get(v, i));
  }
  free(v->items);
}
