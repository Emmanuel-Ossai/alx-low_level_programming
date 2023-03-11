#include "main.h"

/**
 * *_strcat - a C function that appends the src string to the
 * dest string, overwriting the terminating null byte (\0)
 * at the end of dest, and then adds a terminating null byte.
 * @dest:destination string
 * @src:source string
 *
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';
	return (s);
}
