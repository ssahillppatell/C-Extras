#include "../_Utilities/file_handling/file.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  char *content = read_file_and_return_string(filename);

  if (content == NULL) {
    printf("Error: file not found\n");
    return 1;
  }

  Map map = map_create(10);
  map_insert(&map, "key1", 1);
  map_insert(&map, "key2", 2);

  printf("%d\n", map_get(&map, "key1"));
  printf("%d\n", map_get(&map, "key3"));

  map_insert(&map, "key1", 3);
  printf("%d\n", map_get(&map, "key1"));

  map_remove(&map, "key1");
  printf("%d\n", map_get(&map, "key1"));

  map_insert(&map, "key1", 12);
  printf("%d\n", map_get(&map, "key1"));

  free(content);
  return 0;
}
