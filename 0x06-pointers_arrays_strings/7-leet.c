#include "main.h"

/**
 * *leet - a C function that encodes a string into 1337.
 * @s: String to be encoded
 * Return: 0
 */

char *leet(char *s)
{
	int m, n;
	char k[] = "aAeEoOtTlL";
	char l[] = "4433007711";

	for (m = 0; *(s + m); m++)
	{
		for (n = 0; n <= 9; n++)
		{
			if (l[n] == s[m])
				s[m] = l[n];
		}
	}
	return (s);
}
