#include "main.h"


/**
 * check - a C function that checks if a number is prime
 * @x: int to be evaluated
 * @y: int to be evaluated
 *
 * Return: int
 */

int check(int x, int y)
{
	if (y < 2 || y % x == 0)
		return (0);
	else if (x > y / 2)
		return (1);
	else
		return (check(x + 1, y));
}


/**
 * is_prime_number - a C function that returns 1 if the
 * input integer is a prime number, otherwise return 0.
 * @n: int too be evaluated
 *
 * Return:  1 if prime number, otherwise return 0.
 */

int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (check(2, n));
}
