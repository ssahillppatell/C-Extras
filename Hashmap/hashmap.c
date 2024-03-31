#include "hashmap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Map map_create(size_t size) {
  Map map = {0};
  map.size = size;
  map.entries = malloc(size * sizeof(Entry));
  memset(map.entries, 0, size * sizeof(Entry));

  return map;
}

size_t hash(char *key, size_t size) {
  size_t hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash += key[i];
  }
  return hash % size;
}

void map_insert(Map *map, char *key, int value) {
  size_t index = hash(key, map->size);
  if (map->entries[index].key == NULL) {
    map->entries[index].key = key;
    map->entries[index].value = value;
    return;
  } else if (strcmp(map->entries[index].key, key) == 0) {
    map->entries[index].value = value;
    return;
  } else if (map->entries[index].next == NULL) {
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    map->entries[index].next = entry;
    return;
  } else {
    Entry *current = map->entries[index].next;
    while (current->next != NULL) {
      if (strcmp(current->key, key) == 0) {
        current->value = value;
        return;
      }
      current = current->next;
    }
    Entry *entry = malloc(sizeof(Entry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    current->next = entry;
  }
}

int map_get(Map *map, char *key) {
  size_t index = hash(key, map->size);
  if (map->entries[index].key == NULL) {
    return -1;
  } else if (strcmp(map->entries[index].key, key) == 0) {
    return map->entries[index].value;
  } else {
    Entry *current = map->entries[index].next;
    while (current != NULL) {
      if (strcmp(current->key, key) == 0) {
        return current->value;
      }
      current = current->next;
    }
    return -1;
  }
}

int map_remove(Map *map, char *key) {
  size_t index = hash(key, map->size);
  if (map->entries[index].key == NULL) {
    return -1;
  } else if (strcmp(map->entries[index].key, key) == 0) {
    map->entries[index].key = NULL;
    map->entries[index].value = 0;
    return 0;
  } else {
    Entry *current = map->entries[index].next;
    Entry *previous = &map->entries[index];
    while (current != NULL) {
      if (strcmp(current->key, key) == 0) {
        previous->next = current->next;
        free(current);
        return 0;
      }
      previous = current;
      current = current->next;
    }
    return -1;
  }
}
