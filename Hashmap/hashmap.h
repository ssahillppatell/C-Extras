#pragma once
#include <stdlib.h>

typedef struct _Entry Entry;

typedef struct _Entry {
  char *key;
  int value;
} _Entry;

typedef struct Map {
  Entry *entries;
  size_t size;
  size_t capacity;
} Map;

Map map_create();
void map_insert(Map *, char *, int);
int map_get(Map *, char *);
int map_remove(Map *, char *);
int map_key_exist(Map*, char*);
void map_sort(Map*, int (*)(const void*, const void*));


void map_free(Map *);
