#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - a C function that frees a listint_t list.
 * @h: Pointer to the head node of the linked list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *temp;

	if (!h || !*h)
		return (0);

	while (*h != NULL)
	{
		current = *h;
		*h = (*h)->next;
		len++;

		if ((current < *h) || !(*h))
		{
			free(current);
			continue;
		}

		temp = *h;
		while (temp != current)
		{
			len++;
			temp = temp->next;
			free(current);
			current = temp;
		}
	}

	return (len);
}
