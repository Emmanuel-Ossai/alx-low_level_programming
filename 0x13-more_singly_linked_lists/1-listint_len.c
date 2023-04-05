#include "lists.h"

/**
 * listint_len - a C function that returns the number of
 * elements in a linked listint_t list.
 * @h: the head node of the linked list
 *
 * Return: the number of elements in a linked list
 */

size_t listint_len(const listint_t *h)
{
	size_t number = 0;

	for (; h != NULL; h = h->next)
	{
		number++;
	}
	return (number);
}
