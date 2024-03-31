#pragma once
#include <stdlib.h>

typedef struct _Entry Entry;

typedef struct _Entry {
  char *key;
  int value;
  Entry *next;
} _Entry;

typedef struct Map {
  Entry *entries;
  size_t size;
} Map;

Map map_create(size_t);
void map_insert(Map *, char *, int);
int map_get(Map *, char *);
int map_remove(Map *, char *);
