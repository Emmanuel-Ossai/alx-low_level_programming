#include "main.h"

/**
 * print_binary - a C function that prints the binary representation
 * of a number.
 * @n: the number
 *
 * Return: binary representation of a number.
 **/

void print_binary(unsigned long int n)
{
	int count = 0;
	unsigned long int mask = (unsigned long int)1 << 63;

	while (mask > 0)
	{
		if ((n & mask) == mask)
		{
			_putchar('1');
			count++;
		}
		else if (count > 0)
		{
			_putchar('0');
		}
		mask >>= 1;
	}

	if (count == 0)
	{
		_putchar('0');
	}
}
