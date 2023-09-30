#include "hashmap.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashMap HashMap;

Pair *createPair(char *key, void *value)
{
    Pair *new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;

    return new;
}

long hash(char *key, long capacity)
{
  unsigned long hash = 0;

  char *ptr;
    for (ptr = key; *ptr != '\0'; ptr++)
      hash += hash * 32 + tolower(*ptr);
  
  return hash % capacity;
}

int is_equal(void *key1, void *key2)
{
    if (key1 == NULL || key2 == NULL)
      return 0;

    if (strcmp((char *)key1, (char *)key2) == 0)
    return 1;

    return 0;
}

bool isEmptyPair(Pair *pair) {
  
  if (pair == NULL)
    return false;
  
  if (pair->key == NULL)
    return false;

  if (pair->value == NULL)
    return false;

  return true;
}

void insertMap(HashMap *map, char *key, void *value)
{
    if(map == NULL)
        return;

    if (map->size == map->capacity)
      return;

    long pos = hash(key, map->capacity);
    long temp = pos;

    while (isEmptyPair(map->buckets[pos]))
    {
        pos = (pos + 1) % map->capacity;
        if (pos == temp)
            return;
    }

    map->buckets[pos] = createPair(key, value);
    map->current = pos;

    map->size = map->size + 1;
}

void enlarge(HashMap *map)
{
    Pair** old = map->buckets;
    map->buckets = malloc(sizeof(Pair*) * map->capacity * 2);

    long tempCap = map->capacity;
  
    map->capacity *= 2;
    map->size = 0;

    for (long int i = 0; i < tempCap; i++)
    {
        Pair* temp = old[i];
        if(temp != NULL)
            insertMap(map, temp->key, temp->value);
    }

    free(old);
}

HashMap *createMap(long capacity)
{
    HashMap *hashMap = malloc(sizeof(HashMap));

    hashMap->buckets = malloc(capacity * sizeof(Pair*));
    hashMap->capacity = capacity;
    hashMap->current = -1;
    hashMap->size = 0;

    return hashMap;
}

void eraseMap(HashMap *map, char *key)
{
    Pair* temp = searchMap(map, key);
    if (temp != NULL)
    {
        temp->key = NULL;
        map->size--;
    }
  
}

bool searchHelper(Pair *pair, char *key)
{
    if (pair != NULL)
        return is_equal(pair->key, key);

    return false;
}

Pair *searchMap(HashMap *map, char *key)
{
    long pos = hash(key, map->capacity);
    long temp = pos;

    while (!searchHelper(map->buckets[pos], key))
    {
        pos = (pos + 1) % map->capacity;
        if (pos == temp)
            return NULL;
    }

    map->current = pos;

    return map->buckets[pos];
}

Pair *firstMap(HashMap *map)
{
    long pos = map->current;
    long temp = pos;

    while (!isEmptyPair(map->buckets[pos]))
    {
        pos = (pos + 1) % map->capacity;

        if (pos == temp)
            return NULL;
    }

    map->current = pos;
  
    return map->buckets[pos];
}

Pair *nextMap(HashMap *map)
{
    long pos = map->current + 1;

    if (pos >= map->capacity - 1)
        return NULL;

    map->current = pos;
  
    return firstMap(map);
}
