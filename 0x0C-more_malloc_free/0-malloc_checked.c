#include "main.h"

/**
 * malloc_checked - a C function that allocates memory using malloc
 * and Returns a pointer to the allocated memory.
 * @b: the allocated memory
 *
 * Return: a pointer to the allocated memory.
 */


void *malloc_checked(unsigned int b)
{
	void *i;

	i = malloc(b);
	if (i == NULL)
		exit(98);
	return (i);

}
