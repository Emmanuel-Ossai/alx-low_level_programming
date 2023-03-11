#include "main.h"

/**
 * _memcpy - a C function that copies memory.
 * @dest: destination memory area
 * @src: source memory area
 * @n: byte of the memory area
 *
 * Return: pointer to destination memory area
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
