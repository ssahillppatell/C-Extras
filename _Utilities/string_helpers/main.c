#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **string_split_by_characters(char *string, const char *delimiters) {
  char **result = NULL;
  size_t count = 0;
  char *tmp = string;
  char *last = 0;

  while (*tmp) {
    if (strchr(delimiters, *tmp)) {
      count++;
      last = tmp;
    }
    tmp++;
  }

  count += last < (string + strlen(string) - 1);

  count++;

  result = malloc(sizeof(char *) * count);

  if (result) {
    size_t idx = 0;
    char *token = strtok(string, delimiters);

    while (token) {
      *(result + idx++) = strcpy(malloc(strlen(token) + 1), token);
      token = strtok(0, delimiters);
    }
    *(result + idx) = 0;
  }

  return result;
}

char **string_split_by_character(char *string, const char delimiter) {
  const char *delimiters = &delimiter;
  char **result = string_split_by_characters(string, delimiters);
  return result;
}

char *string_ltrim(char *string) {
  while(isspace(*string)) {
    string++;
  }
  return string;
}

char *string_rtrim(char *string) {
  char *end = string + strlen(string) - 1;
  while(end > string && isspace(*end)) {
    end--;
  }
  *(end + 1) = '\0';
  return string;
}


char *string_trim(char *string) {
  return string_rtrim(string_ltrim(string));
}