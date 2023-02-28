#include "main.h"

/**
 * rev_string - a C function that reverses a string.
 * @s: string to be reversed
 * Return: 0
 */

void rev_string(char *s)
{
	int x = 0, y, z;
	char m;

	while (s[x] != '\0')
	{
		x++;
	}
	z = x - 1;
	for (y = 0; z >= 0 && y < z; z--, y++)
	{
		m = s[y];
		s[y] = s[y];
		s[z] = m;
	}
}
