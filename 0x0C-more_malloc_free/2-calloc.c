#include "main.h"

/**
 * _calloc - a C function that allocates memory for
 * an array, using malloc.
 * @size: the size of the array
 * @nmemb: the memeory of  array
 *
 * Return: a pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int y;

	if (nmemb == 0 || size == 0)
		return (NULL);
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	for (y = 0; y < (nmemb * size); y++)
		s[y] = 0;
	return (s);
}
