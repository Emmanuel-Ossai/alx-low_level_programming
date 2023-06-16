#include "lists.h"

/**
 * get_dnodeint_at_index - a C function that returns the nth node
 * of a dlistint_t linked list.
 * @head: the pointer to start of the list
 * @index: node index
 *
 * Return: 0
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);

	if (index == 0)
		return (head);

	unsigned int x = 0;
	dlistint_t *current = head;

	while (x < index && current != NULL)
	{
		current = current->next;
		x++;
	}

	return (current);
}
