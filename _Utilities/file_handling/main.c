#include <stdio.h>
#include <stdlib.h>

char *read_file_and_return_string(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Error: file not found\n");
    return NULL;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);

  fseek(f, 0, SEEK_SET);
  char *buf = malloc(fsize + 1);

  if (buf == NULL) {
    printf("Error: memory allocation failed\n");
    return NULL;
  }

  fread(buf, fsize, 1, f);
  buf[fsize] = '\0'; // null-terminator

  fclose(f);
  return buf;
}
