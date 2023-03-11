#include "main.h"

/**
 * _memset - a C function that fills memory with a constant byte.
 * @s: memory area pointed to
 * @b: constant byte
 * @n: byte of the memory area
 *
 * Return: pointer to the memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
	s[i] = b;
	i++;
	}

	return (s);
}
