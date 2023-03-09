#include "main.h"

/**
 * check - a C function that checks for square root of a number
 * @x: number to be evaluated
 * @y: number to be evaluated
 *
 * Return: int
 */

int check(int x, int y)
{
	if (x * x == y)
		return (x);
	if (x * x > y)
		return (-1);
	return (check(x + 1, y));
}

/**
 * _sqrt_recursion - a C function that returns the
 * natural square root of a number.
 * @n: number to be evaluated
 *
 * Return: int
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}
