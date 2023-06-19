#include "main.h"

/**
 * _islower - C function that checks for lowercase character..
 * Return: 1 if the character is a lowercase character or 0 if otherwise
 * @c: This is the character to be checked by the function
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
