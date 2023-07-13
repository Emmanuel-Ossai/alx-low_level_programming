#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: Size of the hash table.
 *
 * Return: Pointer to the new table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int x;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);

	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;
	sht->array = calloc(size, sizeof(shash_node_t *));
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}

	return (sht);
}

/**
 * make_shash_node - Creates a node for the sorted hash table.
 * @key: Key for the data.
 * @value: Data to be stored.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *shn;

	shn = malloc(sizeof(shash_node_t));
	if (shn == NULL)
		return (NULL);

	shn->key = strdup(key);
	if (shn->key == NULL)
	{
		free(shn);
		return (NULL);
	}

	shn->value = strdup(value);
	if (shn->value == NULL)
	{
		free(shn->key);
		free(shn);
		return (NULL);
	}

	shn->next = NULL;
	shn->sprev = NULL;
	shn->snext = NULL;

	return (shn);
}

/**
 * add_to_sorted_list - Adds a node to the sorted (by key's ASCII) linked list.
 * @table: The sorted hash table.
 * @node: The node to add.
 *
 * Return: void.
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *tmp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}

	tmp = table->shead;
	while (tmp != NULL)
	{
		if (strcmp(node->key, tmp->key) < 0)
		{
			node->snext = tmp;
			node->sprev = tmp->sprev;
			tmp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		tmp = tmp->snext;
	}

	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - Sets a key to a value in the hash table.
 * @ht: The sorted hash table.
 * @key: The key to the data.
 * @value: The data to add.
 *
 * Return: 1 on success, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *shn, *tmp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = new_value;
			return (1);
		}
		tmp = tmp->next;
	}

	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);

	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_to_sorted_list(ht, shn);

	return (1);
}

/**
 * shash_table_get - Retrieves the value associated with
 * a key from the hash table.
 * @ht: Hash table.
 * @key: Key to retrieve the value.
 *
 * Return: The value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || ht->array == NULL ||
		       ht->size == 0 || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);

		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the key-value pairs of a sorted hash table.
 * @ht: Hash table to print.
 *
 * Return: void.
 */
void shash_table_print(const shash_table_t *ht)
{
	if (ht == NULL || ht->shead == NULL)
		return;

	printf("{");
	for (shash_node_t *tmp = ht->shead; tmp != NULL; tmp = tmp->snext)
	{
		if (tmp != ht->shead)
			printf(", ");

		printf("'%s': '%s'", tmp->key, tmp->value);
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the key-value pairs of a sorted
 * hash table in reverse order.
 * @ht: Hash table to print.
 *
 * Return: void.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	if (ht == NULL || ht->stail == NULL)
		return;

	printf("{");
	for (shash_node_t *tmp = ht->stail; tmp != NULL; tmp = tmp->sprev)
	{
		if (tmp != ht->stail)
			printf(", ");

		printf("'%s': '%s'", tmp->key, tmp->value);
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and frees the memory.
 * @ht: Hash table to delete.
 *
 * Return: void.
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;

	for (unsigned long int x = 0; x < ht->size; x++)
	{
		shash_node_t *node = ht->array[x];
		
		while (node != NULL)
		{
			shash_node_t *next = node->next;
			
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}

	free(ht->array);
	free(ht);
}
