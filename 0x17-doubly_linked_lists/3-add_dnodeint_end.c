#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - a C function that adds a new node
 * at the end of a dlistint_t list.
 * @head: the pointer to start of the linked list
 * @n: new node value
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nodenew, *current;

	if (head == NULL)
		return (NULL);
	nodenew = malloc(sizeof(dlistint_t));
	if (nodenew == NULL)
		return (NULL);
	nodenew->n = n;
	nodenew->next = NULL;
	if (*head == NULL)
	{
		nodenew->prev = NULL;
		*head = nodenew;
		return (nodenew);
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = nodenew;
	nodenew->prev = current;
	return (nodenew);
}
