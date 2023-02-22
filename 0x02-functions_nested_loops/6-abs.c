#include "main.h"

/**
 * _abs - C function that computes the absolute value of an integer.
 * Return: The absolute value of the integer
 *
 * @n: This is the interger to be evaluated by the function
 */

int _abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
