#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_empty_character(char c) {
  return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v' ||
         c == '\f';
}

char **string_split_by_characters(char *string, char *delimiters) {
  int count = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    for (int j = 0; delimiters[j] != '\0'; j++) {
      if (string[i] == delimiters[j]) {
        count++;
        break;
      }
    }
  }
  char **result = malloc((count + 1) * sizeof(char *));
  int index = 0;
  int start = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    for (int j = 0; delimiters[j] != '\0'; j++) {
      if (string[i] == delimiters[j]) {
        result[index] = malloc(i - start + 1);
        strncpy(result[index], string + start, i - start);
        result[index][i - start] = '\0';
        index++;
        start = i + 1;
        break;
      }
    }
  }
  result[index] = malloc(strlen(string) - start + 1);
  strncpy(result[index], string + start, strlen(string) - start);
  result[index][strlen(string) - start] = '\0';
  return result;
}

char **string_split_by_character(char *string, char delimiter) {
  char *delimStr = malloc(2);
  delimStr[0] = delimiter;
  delimStr[1] = '\0';
  return string_split_by_characters(string, delimStr);
}
