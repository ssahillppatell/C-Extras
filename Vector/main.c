#include "vector.h"
#include <stdio.h>

int main(int argc, char **argv) {
  Vector *v = vector_init(sizeof(int));

  for (int i = 0; i < 10; ++i) {
    vector_push(v, &i);
  }

  for (int i = 9; i >= 0; --i) {
    printf("%d\n", *(int *)vector_get(v, i));
  }

  return 0;
}
