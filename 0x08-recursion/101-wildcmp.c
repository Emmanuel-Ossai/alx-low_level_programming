#include "main.h"

/**
 * str_checker - a C function that checks strings
 * @s1: string1 to be checked
 * @s2: string2 to be checked
 * @x: left index
 * @y: right index
 * Return: 1 if identical
 */

int str_checker(char *s1, char *s2, int x, int y)
{
	if (s1[x] == '\0' && s2[y] == '\0')
		return (1);
	if (s1[x] == s2[y])
		return (str_checker(s1, s2, x + 1, y + 1));
	if (s1[x] == '\0' && s2[y] == '*')
		return (str_checker(s1, s2, x, y + 1));
	if (s2[y] == '*')
		return (str_checker(s1, s2, x + 1, y) || str_checker(s1, s2, x, y + 1));
	return (0);
}



/**
 * wildcmp - a C function that compares two strings and returns 1 if
 * the strings can be considered identical, otherwise return 0.
 * @s1: string1
 * @s2: string2
 *
 * Return: 1 if identical
 */


int wildcmp(char *s1, char *s2)
{
	return (str_checker(s1, s2, 0, 0));
}
