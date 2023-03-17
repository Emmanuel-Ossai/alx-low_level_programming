#include "main.h"


/**
 * _realloc - a C function that reallocates a memory block
 * using malloc and free
 * @ptr: the pointer to the memory previously allocated
 * @old_size: the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 *
 * Return: a pointer to the new size memory, or NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *c;
	unsigned int x, n = new_size;
	char *oldc = ptr;

	if (ptr == NULL)
	{
		c = malloc(new_size);
		return (c);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	c = malloc(new_size);
	if (c == NULL)
		return (NULL);
	if (new_size > old_size)
		n = old_size;
	for (x = 0; x < n; x++)
		c[x] = oldc[x];
	free(ptr);
	return (c);
}
