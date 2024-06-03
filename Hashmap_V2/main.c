#include "../_Utilities/file_handling/file.h"
#include "../_Utilities/string_helpers/string.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char NEW_LINE = '\n';
const char SPACE = ' ';

char* find_most_frequent_word(Map map) {
  char *most_frequent_word = NULL;
  int most_frequent_word_count = 0;

  for (size_t i = 0; i < map.size; i++) {
    if(map.entries[i].key != NULL) {
      if (map.entries[i].value > most_frequent_word_count) {
        most_frequent_word = map.entries[i].key;
        most_frequent_word_count = map.entries[i].value;

        while(map.entries[i].next != NULL) {
          i++;
          if (map.entries[i].value > most_frequent_word_count) {
            most_frequent_word = map.entries[i].key;
            most_frequent_word_count = map.entries[i].value;
          }
        }
      }
    }
  }

  return most_frequent_word;
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

  Map map = map_create(10000);

  char **lines = string_split_by_character(content, NEW_LINE);

  for (size_t i = 0; lines[i] != NULL; i++) {
    char **tokens = string_split_by_character(lines[i], SPACE);
    
    for(size_t j = 0; tokens[j] != NULL; j++) {
      map_insert(&map, tokens[j], map_get(&map, tokens[j]) == -1 ? 1 : map_get(&map, tokens[j]) + 1);
    }

    free(tokens);
  }

  // Top 10 most frequent words
  char *most_frequent_word = NULL;
  int most_frequent_word_count = 0;
  for(int i = 0; i < 10; i++) {
    most_frequent_word = find_most_frequent_word(map);
    most_frequent_word_count = map_get(&map, most_frequent_word);

    printf("%d. %s --> %d\n", i, most_frequent_word, most_frequent_word_count); 
    map_remove(&map, most_frequent_word);
  }

  free(lines);
  free(content);
  map_free(&map);

  return 0;
}
