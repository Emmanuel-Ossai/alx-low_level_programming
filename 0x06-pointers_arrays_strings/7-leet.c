#include "main.h"

/**
 * *leet - a C function that encodes a string into 1337.
 * @s: String to be encoded
 * Return: 0
 */

char *leet(char *s)
{
	int m, n;
	char m[] = "aAeEoOtTlL";
	char n[] = "4433007711";

	for (i = 0; *(s + m); i++)
	{
		for (n = 0; n <= 9; n++)
		{
			if (m[j] == s[i])
				s[i] = n[j];
		}
	}
	return (s);
}
