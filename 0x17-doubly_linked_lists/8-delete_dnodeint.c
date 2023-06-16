#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - a C function that deletes the node at index
 * of a dlistint_t linked list.
 * @head: the pointer to linked list
 * @index: the index of deletion
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		dlistint_t *temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	dlistint_t *current_node = *head;
	unsigned int x = 0;

	while (x < index && current_node != NULL)
	{
		current_node = current_node->next;
		x++;
	}

	if (current_node == NULL)
		return (-1);

	current_node->prev->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = current_node->prev;

	free(current_node);
	return (1);
}
