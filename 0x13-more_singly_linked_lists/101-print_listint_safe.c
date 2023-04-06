#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * rc - a C function that reallocates memory for an array pointers
 * @list: the old list
 * @size: size of the new list
 * @nn: new node to be added to the list
 *
 * Return: the new list
 */

const listint_t **rc(const listint_t **list, size_t size, const listint_t *nn)
{
	const listint_t **currentlist;
	size_t i;

	currentlist = malloc(size * sizeof(listint_t *));
	if (currentlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		currentlist[i] = list[i];
	currentlist[i] = nn;
	free(list);
	return (currentlist);
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
				free(list);
				return (number);
			}
		}
		number++;
		list = rc(list, number, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (number);
}
