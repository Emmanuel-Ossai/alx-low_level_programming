#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key (string)
 *        The key is unique in the hash table.
 * @value: The value corresponding to a key.
 * @next: A pointer to the next node of the linked list.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;


/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array.
 * @array: An array of size @size.
 *         Each cell of this array is a pointer to the first node
 *         of a linked list,
 *         because we want our hash table to use chaining collision handling.
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* Function to create a hash table */
hash_table_t *hash_table_create(unsigned long int size);

/* Hash function */
unsigned long int hash_djb2(const unsigned char *str);

/* Function to get the index for a given key */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* Function to set a key-value pair in the hash table */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* Function to get the value associated with a key */
char *hash_table_get(const hash_table_t *ht, const char *key);

/* Function to print the hash table */
void hash_table_print(const hash_table_t *ht);

/* Function to delete the hash table */
void hash_table_delete(hash_table_t *ht);


/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key (string)
 *        The key is unique in the hash table.
 * @value: The value corresponding to a key.
 * @next: A pointer to the next node of the linked list.
 * @sprev: A pointer to the previous element of the sorted linked list.
 * @snext: A pointer to the next element of the sorted linked list.
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;


/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array.
 * @array: An array of size @size.
 * @shead: A pointer to the first element of the sorted linked list.
 * @stail: A pointer to the last element of the sorted linked list.
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

/* Function to create a sorted hash table */
shash_table_t *shash_table_create(unsigned long int size);

/* Function to set a key-value pair in the sorted hash table */
int shash_table_set(shash_table_t *ht, const char *key, const char *value);

/* Function to get the value associated with a key in the sorted hash table */
char *shash_table_get(const shash_table_t *ht, const char *key);

/* Function to print the sorted hash table */
void shash_table_print(const shash_table_t *ht);

/* Function to print the sorted hash table in reverse */
void shash_table_print_rev(const shash_table_t *ht);

/* Function to delete the sorted hash table */
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
