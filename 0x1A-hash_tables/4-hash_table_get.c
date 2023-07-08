#include "hash_tables.h"

/**
 * hash_table_get - a C function that retrieves value associated with a key
 * @ht: The hash table to retrieve the value from.
 * @key: The key to find the value.
 *
 * Return: The value associated with the key, or NULL if the key
 * couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	if (ht == NULL || ht->array == NULL ||
			ht->size == 0 || key == NULL || *key == '\0')
		return (NULL);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}
