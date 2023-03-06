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
	int i;
		while (*s)
		{
			for (i = 0; accept[i]; i++)
			{
				if (*s == accept[i])
					return (s);
			}
			s++;
		}
	return (NULL);
}
