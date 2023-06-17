#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - a C function that adds a new node at the
 * beginning of a dlistint_t list.
 * @head: the pointer to start of the linked list
 * @n: new node value
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *next_node = NULL;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	if (*head != NULL)
	{
		next_node = *head;
		new_node->next = next_node;
		next_node->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*head = new_node;

	return (new_node);
}
