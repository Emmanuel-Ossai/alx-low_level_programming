#include "main.h"

/**
 * _strchr - a C function that locates a character in a string.
 * @s: character to be located
 * @c: string
 *
 * Return: character or null if not found
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
