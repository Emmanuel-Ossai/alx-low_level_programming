#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - a C function that deletes the head node of a listint_t
 * linked list, and returns the head node’s data (n).
 * @head: Pointer to the head node of the linked list
 *
 * Return: the head node’s data (n)
 */

int pop_listint(listint_t **head)
{
	listint_t *current;
	int node_data;

	if (head == NULL || *head == NULL)
		return (0);
	current = *head;
	*head = current->next;
	node_data = current->n;
	free(current);
	return (node_data);
}
