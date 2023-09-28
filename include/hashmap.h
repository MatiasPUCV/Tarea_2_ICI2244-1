#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct Pair
{
    char* key;
    void* value;
} Pair;

typedef struct HashMap {
    Pair **buckets;
    long size;
    long capacity;
    long current;
} HashMap;

HashMap* createMap(long capacity);

void insertMap(HashMap* table, char* key, void* value);
void eraseMap(HashMap* table, char* key);
void enlarge(HashMap* map);

Pair* searchMap(HashMap* table, char* key);
Pair* firstMap(HashMap* table);
Pair* nextMap(HashMap* table);

#endif // HASHMAP_H
