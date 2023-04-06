#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rc - a C function that reallocates memory
 * @size: size of new list
 * @list: list to be attached
 * @nn: the new node
 *
 * Return: the size of the list that was freed
 */


listint_t **rc(listint_t **list, size_t size, listint_t *nn)
{
	listint_t **list_list;
	size_t i;

	list_list = malloc(size * sizeof(listint_t *));
	if (list_list == NULL)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		list_list[i] = list[i];
	list_list[i] = nn;
	free(list);
	return (list_list);
}


/**
 * free_listint_safe - a C function that frees a listint_t list.
 * @h: Pointer to the head node of the linked list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t i, number = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (h == NULL || *h == NULL)
		return (number);
	while (*h != NULL)
	{
		for (i = 0; i < number; i++)
		{
			if (*h == list[i])
			{
				*h = NULL;
				free(list);
				return (number);
			}
		}
		number++;
		list = rc(list, number, *h);
		next = (*h)->next;
		free(*h);
		*h = next;
	}
	free(list);
	return (number);
}
