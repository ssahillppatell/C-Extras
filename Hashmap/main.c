#include "../_Utilities/file_handling/file.h"
#include "../_Utilities/string_helpers/string.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char NEW_LINE = '\n';
const char SPACE = ' ';

int comparator(const void* a, const void* b) {
  return ((Entry*)b)->value - ((Entry*)a)->value;
}

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

  Map map = map_create(100000);

  char **lines = string_split_by_character(content, NEW_LINE);

  for (size_t i = 0; lines[i] != NULL; i++) {
    char **tokens = string_split_by_character(lines[i], SPACE);
    
    for(size_t j = 0; tokens[j] != NULL; j++) {
      map_insert(&map, tokens[j], map_get(&map, tokens[j]) == -1 ? 1 : map_get(&map, tokens[j]) + 1);
    }

    free(tokens);
  }

  map_sort(&map, comparator);

  for(size_t i = 0; i < 10; i++) {
    printf("%s: %d\n", map.entries[i].key, map.entries[i].value);
  }

  free(lines);
  free(content);
  map_free(&map);

  return 0;
}