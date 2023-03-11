#include "main.h"

/**
 * _puts - a C function that prints a string, followed
 * by a new line, to stdout.
 * @str: string to be printed
 *
 * Return: lenght of the string
 */

void _puts(char *str)
{
	int x = 0;

	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
	_putchar('\n');
}
