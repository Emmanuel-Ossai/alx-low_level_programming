#include "main.h"

/**
 *  _strspn - a C function that gets the length of a prefix substring.
 * @s: initial segment
 * @accept: accept byte
 *
 * Return: number of bytes in the initail  segment
 */

unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j, k;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != 32)
		{
			for (j = 0; accept[j] != '\0'; j++)
			{
				if (s[i] == accept[j])
					k++;
			}
		}
		else
			return (k);
	}
		return (k);

}
