#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - a C function that adds a new node at the
 * beginning of a listint_t list.
 * @head: Pointer to the head node of the linked list
 * @n: integer to be added to new node
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}
