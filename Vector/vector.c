#include "vector.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 256

Vector *vector_init(int item_size) {
  Vector *v = malloc(sizeof(Vector));

  if (v == NULL) {
    return NULL;
  }

  v->item_size = item_size;
  v->size = 0;
  v->capacity = INITIAL_CAPACITY;
  v->items = malloc(v->capacity * item_size);

  if (v->items == NULL) {
    free(v);
    return NULL;
  }

  return v;
}

void vector_push(Vector *v, void *item) {
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->items = realloc(v->items, v->capacity * v->item_size);
    if(v->items == NULL) {
      return;
    }
  }
  memcpy((char *)v->items + v->size * v->item_size, item, v->item_size);
  v->size++;
}

void vector_push_front(Vector *vector, void *item) {
  if (vector->size == vector->capacity) {
    vector->capacity *= 2;
    vector->items =
        realloc(vector->items, vector->capacity * vector->item_size);
    if (vector->items == NULL) {
      return;
    }
  }
  memmove((char *)vector->items + vector->item_size, vector->items,
          vector->size * vector->item_size);
  memcpy(vector->items, item, vector->item_size);
  vector->size++;
}

void *vector_pop(Vector *v) {
  if (v->size == 0) {
    return NULL;
  }
  return (char *)v->items + --v->size * v->item_size;
}

void *vector_pop_front(Vector *v) {
  if (v->size == 0) {
    return NULL;
  }
  void *item = malloc(v->item_size);
  if (item == NULL) {
    return NULL;
  }

  memcpy(item, v->items, v->item_size);
  memmove(v->items, (char *)v->items + v->item_size, --v->size * v->item_size);
  return item;
}

void *vector_get(Vector *v, int index) {
  return (char *)v->items + index * v->item_size;
}

void *vector_front(Vector *v) { return vector_get(v, 0); }

void *vector_back(Vector *v) { return vector_get(v, v->size - 1); }

void vector_sort(Vector *v, int (*comparator)(const void *, const void *)) {
  qsort(v->items, v->size, v->item_size, comparator);
}

void vector_free(Vector *v) {
  for (size_t i = 0; i < v->size; i++) {
    free(vector_get(v, i));
  }
  free(v->items);
}
