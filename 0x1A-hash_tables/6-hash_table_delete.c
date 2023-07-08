#include "hash_tables.h"

/**
 * hash_table_delete - a C function that deletes a hash table and contents
 * @ht: The hash table to delete.
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	unsigned long int x;
	hash_node_t *current_node, *next_node;

	for (x = 0; x < ht->size; x++)
	{
		current_node = ht->array[x];
		while (current_node != NULL)
		{
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
		}
	}

	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
