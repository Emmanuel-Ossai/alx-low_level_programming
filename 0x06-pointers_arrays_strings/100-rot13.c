#include "main.h"

/**
 * *rot13 - a C function that encodes a string using rot13.
 * @s: String to be encoded
 *
 * Return: 0
 */

char *rot13(char *s)
{
	int m, n;
	char l[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char k[] = "lmnopqrstuvwxyzabcdefghijkLMNOPQRSTUVWXYZABCDEFGHIJK";

	for (m = 0; *(s + m); m++)
	{
		for (n = 0; n < 52; n++)
		{
			if (l[n] == *(s + m))
			{
				*(s + m) = k[n];
				break;
			}
		}
	}
	return (s);
}
