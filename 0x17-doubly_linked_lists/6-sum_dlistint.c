#include "lists.h"

/**
 * sum_dlistint - a C function that returns the sum of all
 * the data (n) of a dlistint_t linked list.
 * @head: the pointer to start of the linked list
 *
 * Return: 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);

	int sum = head->n;
	dlistint_t *current = head->next;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
