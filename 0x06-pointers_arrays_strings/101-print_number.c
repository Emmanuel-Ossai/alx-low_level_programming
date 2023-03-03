#include "main.h"

/**
 * print_number - a C function that prints an integer.
 * @n: Number to be printed
 * Return: 0
 */


void print_number(int n)
{
	unsigned int b;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
	}

	b = n;

	if (b / 10)
		print_number(b / 10);

	_putchar(b % 10 + '0');
}
