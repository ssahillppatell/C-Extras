#include "hashmap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 100000

Map map_create(size_t capacity) {
    Map map = {0};

    map.size = 0;
    map.capacity = capacity ? capacity : INITIAL_SIZE;
    map.entries = malloc(sizeof(Entry) * map.capacity);
    memset(map.entries, 0, sizeof(Entry) * map.capacity);

    return map;
}

void manage_capacity(Map* map) {
    if(map->size == map->capacity) {
        map->capacity = map->capacity << 1;
        map->entries = realloc(map->entries, sizeof(Entry) * map -> capacity);
    }
}

size_t djb2 (char* str) {
    size_t hash = 5381;
    int c;

    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

size_t hash(char* key, size_t capacity) {
    return djb2(key) % capacity;
}

void map_insert(Map* map, char* key, int val) {
    manage_capacity(map);

    size_t index = hash(key, map->capacity);

    while(map->entries[index].key != 0) {
        if(strcmp(map->entries[index].key, key) == 0) {
            map->entries[index].value = val;
            return;
        }
        index++;
    }
    map->entries[index].key = key;
    map->entries[index].value = val;
    map->size++;
}

int map_get(Map* map, char* key) {
    size_t index = hash(key, map->capacity);

    while(map->entries[index].key != 0) {
        if(strcmp(map->entries[index].key, key) == 0) {
            return map->entries[index].value;
        }
        index++;
    }
    return -1;
}

int map_remove(Map* map, char* key) {
    size_t index = hash(key, map->capacity);

    while(map->entries[index].key != 0) {
        if(strcmp(map->entries[index].key, key) == 0) {
            int val = map->entries[index].value;
            map->entries[index].key = 0;
            return val;
        }
        index++;
    }

    return -1;
}

int map_key_exist(Map* map, char* key) {
    size_t index = hash(key, map->capacity);

    while(map->entries[index].key != 0) {
        if(strcmp(map->entries[index].key, key) == 0) {
            return 1;
        }
        index++;
    }
    return 0;
}

void map_sort(Map* map, int(*comparator)(const void*, const void*)) {
    qsort(map->entries, map->capacity, sizeof(Entry), comparator);
}

void map_free(Map* map) {
    free(map->entries);
}