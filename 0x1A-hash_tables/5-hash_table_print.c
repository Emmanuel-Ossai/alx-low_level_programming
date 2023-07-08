#include "hash_tables.h"

/**
 * hash_table_print - a C function that prints the key/value
 * pairs of a hash table.
 * @ht: The hash table to print.
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	if (ht == NULL || ht->array == NULL)
		return;

	unsigned long int x;
	hash_node_t *node;
	int printed = 0;

	printf("{");
	for (x = 0; x < ht->size; x++)
	{
		node = ht->array[x];
		while (node != NULL)
		{
			if (printed == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			printed = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
