#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rc - a C function that reallocates memory for an array pointers
 * @list: the old list
 * @size: size of the new list
 * @new: new node to be added to the list
 *
 * Return: the new list
 */

const listint_t **rc(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
	size_t i;

	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	if (list != NULL)
	{
		for (i = 0; i < size - 1; i++)
			newlist[i] = list[i];
		free(list);
	}
	newlist[i] = new;
	return (newlist);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the numberber of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i, number = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < number; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				while (number-- > i)
					free((void *)list[number]);
				free(list);
				return (i);
			}
		}
		number++;
		list = rc(list, number, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	while (number-- > 0)
		free((void *)list[number]);
	free(list);
	return (number);
}
