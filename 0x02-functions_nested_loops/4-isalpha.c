#include "main.h"

/**
 * _isalpha - C function that checks for alphabetic character..
 * Return: 1 if the character is a letter, lowercase
 * or uppercase character and 0 if otherwise
 * @c: This is the character to be checked by the function
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z' && c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
