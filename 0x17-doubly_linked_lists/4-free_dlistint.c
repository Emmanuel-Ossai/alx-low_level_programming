#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - a C function that frees a dlistint_t list.
 * @head: the pointer to start of the linked list
 *
 * Return: 0
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;

	while (current != NULL)
	{
		dlistint_t *next = current->next;

		free(current);
		current = next;
	}
}
