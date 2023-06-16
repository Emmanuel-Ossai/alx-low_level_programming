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

	while (index > 0 && head != NULL)
	{
		head = head->next;
		index--;
	}

	return (head);
}
