#include <stdlib.h>
#include "lists.h"


/**
 * list_len - a C function that returns the number of elements
 * in a linked list_t list.
 * @h: the list name
 *
 * Return: the number of elements
 */

size_t list_len(const list_t *h)
{
int count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}

