#include "lists.h"
#include <stdlib.h>
#include <stdio.h>


size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - a C function that Counts the number of unique nodes
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t nodes = 0;

	if (head == NULL)
		return (nodes);

	while (hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			do {
				nodes++;
				hare = hare->next;
			} while (tortoise != hare);

			return (nodes);
		}
	}

	while (head != NULL)
	{
		nodes++;
		head = head->next;
	}

	return (nodes);
}



/**
 * print_listint_safe - a C function that prints a listint_t linked list.
 * @head: Pointer to the head node of the linked list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);

		nodes++;

		if (head > head->next)

		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}

		head = head->next;
	}

	return (nodes);
}
