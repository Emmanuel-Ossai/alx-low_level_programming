#include "lists.h"

/**
 * reverse_listint - a C function that reverses a listint_t linked list.
 * @head: Pointer to the head node of the linked list
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current = *head;
	listint_t *prev = NULL;

	while (current)
	{
		listint_t *next = current->next;

		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return (*head);
}
