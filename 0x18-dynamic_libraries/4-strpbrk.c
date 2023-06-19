#include "main.h"

/**
 * _strpbrk - a C function that searches a string for
 * any of a set of bytes.
 * @s: first occurence in the string
 * @accept: the string
 *
 * Return: pointer to the byte in teh string
 */


char *_strpbrk(char *s, char *accept)
{
		int k;

		while (*s)
		{
			for (k = 0; accept[k]; k++)
			{
			if (*s == accept[k])
			return (s);
			}
		s++;
		}

	return ('\0');
}
