#include "main.h"

/**
 * _strlen - a C function that returns the length of a string.
 * @s: character to be checked
 *
 * Return: 0
 */

int _strlen(char *s)
{
	int x = 0;

	for (; *s++;)
		x++;
	return (x);
}
