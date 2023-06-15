#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - a C function that prints all the elements
 * of a dlistint_t list.
 * @h: the pointer to start of the linked list
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t x = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		x++;
	}

	return (x);
}
