#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - a C function that frees a listint_t list.
 * @head: Pointer to the head node of the linked list
 *
 * Return: frees all elements of a list
 */

void free_listint(listint_t *head)
{
	listint_t *current = head;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
