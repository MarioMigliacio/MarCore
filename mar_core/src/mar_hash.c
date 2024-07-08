/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_hash.c                                                                             */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_hash.h"
#include <stdlib.h>     // malloc
#include <string.h>     // _strdup

/*
 * \brief Magic number used in the djb2 hash function, which is a
 * popular and effective hash function created by Daniel J. Bernstein.
 */
#define HASH_SEED 5381

/*
 * \brief The number 32 is used because it is a simple yet effective multiplier that 
 * helps to spread the hash values uniformly, reducing the likelihood of collisions.
 */
#define HASH_SHIFT 5

/*
 * \brief HashNode is an internal structure to making a HashMap data type.
 */
typedef struct HashNode
{
    char *key;                  // \brief Element in HashMap is referred to as a Key/Value combination of type <string, void*>
    void *value;                // \brief Element in HashMap is referred to as a Key/Value combination of type <string, void*>
    struct HashNode *next;      // \brief Next is a single linked list of type Key/Value/Next* type.
} HashNode;

/*
 * \brief HashMap Data type represents a key/value combination of any type of data, keyed by string.
 */
struct HashMap
{
    HashNode **buckets; // \brief A pointer to the base Address of the starting HashNode array
    u64 size;           // \brief The size allocated for this HashMap
};

/*
 * \brief A function which provides semi unique buckets for keys.
 *
 * \details - INTERNAL FUNCTION, NOT EXPOSED PUBLICLY
 * The hash_function in a hashmap is used to convert keys into hash values.
 * These hash values are then used to determine the index at which the key-value
 * pair should be stored in the hash table. A good hash function should
 * distribute keys uniformly across the hash table to minimize collisions,
 * where multiple keys hash to the same index.
 */
static u64 hash_function(const char *str, u64 size)
{
    u64 hash = HASH_SEED;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << HASH_SHIFT) + hash) + c;   // 32 + hash = 33 multiplier, plus constant. Even distribution
    }

    return hash % size; // an index appropriate location to emplace.
}

/*
 * \brief A function which creates a dynamic allocated pointer to a HashNode
 *
 * \details - INTERNAL FUNCTION, NOT EXPOSED PUBLICLY
 * The create_node in a hashmap is used to generate a HashNode object and return a pointer to it
 * and return a pointer to it.
 */
HashNode* create_node(const char* key, void* value)
{
    if (!key)
    {
        return NULL;
    }

    HashNode* node = (HashNode*)malloc(sizeof(HashNode));

    if (node)
    {
        u64 key_len = strlen(key);
        node->key = (char*)malloc(key_len + 1);

        if (node->key)
        {
            errno_t err = strncpy_s(node->key, key_len + 1, key, key_len);

            if (err != 0)
            {
                free(node->key);
                free(node);
                return NULL;
            }

            node->key[key_len] = '\0';
        }
        else
        {
            free(node);
            return NULL;
        }

        node->value = value;
    }

    return node;
}

HashMap* hashmap_init(u64 size)
{
    HashMap *map = (HashMap*)malloc(sizeof(HashMap));

    if (!map)
    {
        return NULL;
    }

    map->buckets = (HashNode**)calloc(size, sizeof(HashNode*));

    if (!map->buckets)
    {
        free(map);

        return NULL;
    }

    map->size = size;

    return map;
}

u8 hashmap_insert(HashMap *map, const char *key, void *value)
{
    if (!map || !key)
    {
        return FALSE;
    }

    u64 index = hash_function(key, map->size);
    HashNode *new_node = create_node(key, value);

    if (!new_node)
    {
        return FALSE;
    }

    new_node->key = _strdup(key);      // _strdup syscall - "I promise to free this memory." - mario

    if (!new_node->key)
    {
        free(new_node);

        return FALSE;
    }

    new_node->value = value;
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;

    return TRUE;
}

void* hashmap_lookup(const HashMap *map, const char *key)
{
    if (!map || !key)
    {
        return FALSE;
    }

    u64 index = hash_function(key, map->size);
    HashNode *node = map->buckets[index];

    while (node)
    {
        u64 key_len = strlen(key);

        if (strncmp(node->key, key, key_len) == 0)
        {
            return node->value;                     // The correct key was identified, return not null
        }

        node = node->next;
    }

    return NULL;
}

u8 hashmap_remove_at(HashMap *map, const char *key)
{
    if (!map || !key)
    {
        return FALSE;
    }

    u64 index = hash_function(key, map->size);
    HashNode *node = map->buckets[index];
    HashNode *prev = NULL;

    while (node)
    {
        u64 key_len = strlen(key);

        if (strncmp(node->key, key, key_len) == 0)
        {
            if (prev)
            {
                prev->next = node->next;
            }
            else
            {
                map->buckets[index] = node->next;
            }

            free(node->key);
            free(node);

            return TRUE;    // The correct key has been removed, bucket at index shifted.
        }

        prev = node;
        node = node->next;
    }

    return FALSE;
}

void hashmap_free(HashMap *map)
{
    if (!map)
    {
        return;
    }

    for (u64 i = 0; i < map->size; i++)
    {
        HashNode *node = map->buckets[i];

        while (node)
        {
            HashNode *temp = node;
            node = node->next;
            free(node->key);
            free(node);
        }
    }

    free(map->buckets);
    free(map);
}
