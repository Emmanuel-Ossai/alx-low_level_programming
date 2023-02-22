#include "main.h"

/**
 * print_last_digit - C function that prints the last digit of a number.
 * Return: the value of the last digit
 * @n: This is the number to be evaluated by the function
 */

int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (last_digit < 0)
		last_digit *= -1;

	_putchar(last_digit + '0');

	return (last_digit);
}
