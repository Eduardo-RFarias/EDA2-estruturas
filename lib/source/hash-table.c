#include "hash-table.h"

HashTable *ht_init(int maxSize, int maxCollisions)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));

    ht->maxSize = maxSize;
    ht->maxCollisions = maxCollisions;

    ht->table = (KV *)calloc(sizeof(KV), maxSize);

    return ht;
}

void ht_free(HashTable *ht)
{
    free(ht->table);
    free(ht);
}

void ht_insert(HashTable *ht, int key, int value)
{
    int hash = ht_hash(key);
    int collisions = 0;

    while (ht->table[hash].key != 0)
    {
        hash++;
        collisions++;

        if (collisions > ht->maxCollisions)
        {
            fprintf(stderr, "Hash table overflow\n");
            exit(1);
        }
    }

    ht->table[hash].key = key;
    ht->table[hash].value = value;
}

int ht_get(HashTable *ht, int key)
{
    int hash = ht_hash(key);
    int collisions = 0;

    while (ht->table[hash].key != key)
    {
        hash++;
        collisions++;

        if (collisions > ht->maxCollisions)
            return 0;
    }

    return ht->table[hash].value;
}