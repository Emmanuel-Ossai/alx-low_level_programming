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
	if (head == NULL)
		return (NULL);

	dlistint_t *newNodePtr = malloc(sizeof(dlistint_t));
	
	if (newNodePtr == NULL)
		return (NULL);

	newNodePtr->n = n;
	newNodePtr->next = NULL;

	if (*head == NULL)
	{
		newNodePtr->prev = NULL;
		*head = newNodePtr;
		return (newNodePtr);
	}

	dlistint_t *tmpPtr = *head;
	while (1)
	{
		if (tmpPtr->next == NULL)
		{
			tmpPtr->next = newNodePtr;
			newNodePtr->prev = tmpPtr;
			break;
		}
		tmpPtr = tmpPtr->next;
	}

	return (newNodePtr);
}
