#include "lists.h"

/**
 * get_nodeint_at_index - a C function that returns the nth node
 * of a listint_t linked list.
 * @head: Pointer to the head node of the linked list
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node of a linked list
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *node = head;

	while (node && i < index)
	{
		node = node->next;
		i++;
	}

	return (node);
}
