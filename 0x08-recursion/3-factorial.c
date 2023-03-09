#include "main.h"

/**
 * factorial  - a C function that returns the factorial of a given number.
 * @n: the integer to be evaluated
 *
 * Return: 1 or -1 if n is lower than 0, to indicate an error
 */

int factorial(int n)
{
	int i;

	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	else
	{
		i = n * factorial(n - 1);
	}
			return (i);

}
