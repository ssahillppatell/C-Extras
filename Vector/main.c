#include "vector.h"
#include <stdio.h>

int int_cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  Vector *v = vector_init(sizeof(int));

  vector_push(v, &(int){123});
  vector_push(v, &(int){456});
  vector_push(v, &(int){79});
  vector_push_front(v, &(int){0});
  vector_push_front(v, &(int){-1});
  vector_push(v, &(int){3});

  vector_sort(v, int_cmp);

  for (size_t i = 0; i < v->size; i++) {
    printf("%d\n", *(int *)vector_get(v, i));
  }

  return 0;
}
