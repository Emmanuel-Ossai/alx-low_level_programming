#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - a C function that inserts a new
 * node at a given position.
 * @h: the double pointer to start of linked list
 * @idx: the index of the list where the new node should be added
 * @n: new node value
 *
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	if (h == NULL)
		return (NULL);

	dlistint_t *newNode = malloc(sizeof(dlistint_t));

	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (idx == 0)
	{
		if (*h != NULL)
			(*h)->prev = newNode;
		newNode->next = *h;
		*h = newNode;
		return (newNode);
	}
	dlistint_t *current = *h;
	unsigned int x = 0;

	while (x < idx - 1 && current != NULL)
	{
		current = current->next;
		x++;
	}
	if (current == NULL)
	{
		free(newNode);
		return (NULL);
	}
	newNode->prev = current;
	newNode->next = current->next;
	current->next = newNode;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;

	return (newNode);
}
