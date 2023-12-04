#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int key;
    int value;
} KV;

typedef struct
{
    int maxSize;
    int maxCollisions;
    KV *table;
} HashTable;

#define ht_hash(key) (key % ht->maxSize)

HashTable *ht_init(int maxSize, int maxCollisions);

void ht_free(HashTable *ht);

void ht_insert(HashTable *ht, int key, int value);

int ht_get(HashTable *ht, int key);

#endif // HASH_TABLE_H