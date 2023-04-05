#include "lists.h"

/**
 * reverse_listint - a C function that reverses a listint_t linked list.
 * @head: Pointer to the head node of the linked list
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->next = previous;
		previous = current;
		current = next;
	}

	*head = previous;

	return (*head);
}
