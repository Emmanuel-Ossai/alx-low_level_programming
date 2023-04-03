#include <stdio.h>
#include "lists.h"

/**
 * print_listint - a C function that prints all the elements
 * of a listint_t list.
 * @h: the head node of the linked list
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		count++;
	}
	return (count);
}
