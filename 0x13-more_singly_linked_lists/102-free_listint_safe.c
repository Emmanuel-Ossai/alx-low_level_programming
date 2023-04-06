#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - a C function that frees a listint_t list.
 * @head: Pointer to the head node of the linked list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *current, *next;

	if (head == NULL || *head == NULL)
		return (count);

	while (*head != NULL)
	{
		current = *head;
		next = current->next;

		free(current);
		*head = NULL;
		count++;
		if (next == NULL || next < current)
			break;

		*head = next;
	}

	return (count);
}
