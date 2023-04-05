#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - a C function that inserts a new node at
 * a given position.
 * @head: Pointer to the head node of the linked list
 * @idx: the index of the list where the new node should be added.
 * @n: data to be added to the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0 || *head == NULL)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (idx > 1 && current->next != NULL)
	{
		current = current->next;
		idx--;
	}

	if (idx > 1)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
