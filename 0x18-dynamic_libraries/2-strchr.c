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
	int x = 0;

	for (; s[x] >= '\0'; x++)
	{
		if (s[x] == c)
			return (&s[x]);
	}
	return (0);
}
