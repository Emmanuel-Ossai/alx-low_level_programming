#include "main.h"

/**
 * _strcmp - a C function that compares two strings.
 * @s1: String1
 * @s2: String2
 *
 * Return: String
 */

int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
