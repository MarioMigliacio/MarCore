/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_hash.c                                                                              */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: mc_hash.h is linked properly and defines interface                                  */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_hash.h"
#include <stdlib.h>     // malloc
#include <string.h>     // _strdup
#include <stdio.h>      // printf

/**
 * \brief Magic number used in the djb2 hash function, which is a
 * popular and effective hash function created by Daniel J. Bernstein.
 */
#define HASH_SEED 5381

/**
 * \brief The number 32 is used because it is a simple yet effective multiplier that 
 * helps to spread the hash values uniformly, reducing the likelihood of collisions.
 */
#define HASH_SHIFT 5

/**
 * \brief HashNode is an internal structure to making a HashMap data type.
 */
typedef struct HashNode
{
    char *key;                  // \brief Element in HashMap is referred to as a Key/Value combination of type <string, void*>
    void *value;                // \brief Element in HashMap is referred to as a Key/Value combination of type <string, void*>
    u8 isDynamic;               // \brief Element is created with dyanmic memory and needs to be freed, TRUE / FALSE.
    struct HashNode *next;      // \brief Next is a single linked list of type Key/Value/Next* type.
} HashNode;

/**
 * \brief HashMap Data type represents a key/value combination of any type of data, keyed by string.
 */
struct MC_HashMap
{
    HashNode **buckets; // \brief A pointer to the base Address of the starting HashNode array
    u64 size;           // \brief The size allocated for this HashMap
};

/**
 * \brief A function which provides semi unique buckets for keys.
 *
 * \details - INTERNAL FUNCTION, NOT EXPOSED PUBLICLY
 * The hash_function in a hashmap is used to convert keys into hash values.
 * These hash values are then used to determine the index at which the key-value
 * pair should be stored in the hash table. A good hash function should
 * distribute keys uniformly across the hash table to minimize collisions,
 * where multiple keys hash to the same index.
 */
static u64 internal_hash_function(const char *str, u64 size)
{
    u64 hash = HASH_SEED;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << HASH_SHIFT) + hash) + c;   // 32 + hash = 33 multiplier, plus constant. Even distribution
    }

    return hash % size;
}

MC_HashMap* MC_Hashmap_Init(u64 size)
{
    MC_HashMap *map = (MC_HashMap*)malloc(sizeof(MC_HashMap));

    if (!map)
    {
        return NULL;
    }

    map->buckets = (HashNode**)calloc(sizeof(HashNode*), size);

    if (!map->buckets)
    {
        free(map);

        return NULL;
    }

    map->size = size;

    return map;
}

u8 MC_Hashmap_Insert(MC_HashMap *map, const char *key, void *value, const u8 dynamic)
{
    if (!map || !key)
    {
        return false;
    }

    u64 index = internal_hash_function(key, map->size);
    HashNode *new_node = map->buckets[index];

    while (new_node != NULL)
    {
        if (strncmp(new_node->key, key, strlen(key)) == 0)  // key already exists, update value and dynamic flag
        {
            if (new_node->isDynamic)
            {
                free(new_node->value);
            }

            new_node->value = value;
            new_node->isDynamic = dynamic;

            return true;
        }

        new_node = new_node->next;
    }

    new_node = (HashNode *)malloc(sizeof(HashNode));    // Key didn't exist, create new HashNode and insert it
    
    if (!new_node)
    {
        return false;
    }

    new_node->key = _strdup(key);   // _strdup syscall - "I promise to free this memory." - mario
    new_node->value = value;
    new_node->isDynamic = dynamic;
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;

    return true;
}

void* MC_Hashmap_Search(const MC_HashMap *map, const char *key)
{
    if (!map || !key)
    {
        return false;
    }

    u64 index = internal_hash_function(key, map->size);
    HashNode *node = map->buckets[index];

    while (node)
    {
        if (strncmp(node->key, key, strlen(key)) == 0)
        {
            return node->value;
        }

        node = node->next;
    }

    return NULL;
}

u8 MC_Hashmap_RemoveAt(MC_HashMap *map, const char *key)
{
    if (!map || !key)
    {
        return false;
    }

    u64 index = internal_hash_function(key, map->size);
    HashNode *node = map->buckets[index];
    HashNode *prev = NULL;

    while (node)
    {
        /* this check is incase something else hashed to the same index, but was not the 'key' being searched */
        if (strncmp(node->key, key, strlen(key)) == 0)
        {
            if (prev)
            {
                prev->next = node->next;
            }
            else
            {
                map->buckets[index] = node->next;
            }

            if (node->isDynamic)
            {
                free(node->value);
            }

            free(node->key);
            free(node);

            return true;
        }

        prev = node;
        node = node->next;
    }

    return false;
}

void MC_Hashmap_Free(MC_HashMap **map_ptr)
{
    if (!(map_ptr) || !(*map_ptr))
    {
        return;
    }

    MC_HashMap *map = *map_ptr;

    for (u64 i = 0; i < map->size; i++)
    {
        HashNode *node = map->buckets[i];

        while (node)
        {
            HashNode *next = node->next;

            if (node->isDynamic)
            {
                free(node->value);
            }

            free(node->key);
            free(node);

            node = next;
        }

        map->buckets[i] = NULL;
    }

    free(map->buckets);
    free(map);

    *map_ptr = NULL;
}

void MC_Hashmap_Print(const MC_HashMap *map)
{
    printf("Start Table\n");

    for (u64 i = 0; i < map->size; i++)
    {
        if (map->buckets[i] == NULL)
        {
            printf("\t%lld\t---\n", i);
        }
        else
        {
            printf("\t%lld\t", i);

            HashNode *node = map->buckets[i];
            while (node != NULL)
            {
                printf("\"%s\"(%p) - ", node->key, node->value);
                node = node->next;
            }

            printf("\n");
        }
    }

    printf("End Table\n");
}