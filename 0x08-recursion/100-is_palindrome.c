#include "main.h"

/**
 * _strlen_recursion - a C function that checks the length of a string
 * @s: string to be evaluated
 *
 * Return: int
 */

int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));
	return (0);
}


/**
 * pal_checker - a C function that checks for palindrome
 * @s: string address
 * @x: left index
 * @y: right index
 *
 * Return: 1 if palindrome and 0 if not
 */

int pal_checker(char *s, int x, int y)
{
	if (s[x] == s[y])
		if (x > y / 2)
			return (1);
		else
			return (pal_checker(s, x + 1, y - 1));
	else
		return (0);
}


/**
 * is_palindrome - a C function that returns 1 if a string
 * is a palindrome and 0 if not.
 * @s: string to be evaluated
 *
 * Return: 1 if palindrome and 0 if not
 */


int is_palindrome(char *s)
{
	return (pal_checker(s, 0, _strlen_recursion(s) - 1));
}
