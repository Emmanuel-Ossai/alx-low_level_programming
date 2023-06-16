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
	int add_all = 0;

	while (head != NULL)
	{
		add_all += head->n;
		head = head->next;
	}
	return (add_all);
}
