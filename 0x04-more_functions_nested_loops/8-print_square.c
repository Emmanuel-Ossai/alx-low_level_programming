#include "main.h"

/**
 * print_square - a C function that prints a square,
 * followed by a new line.
 * @size: is the size of the square
 * Return: 0
 */


void print_square(int size)
{
	int x, y;

	if (size <= 0)
		_putchar('\n');

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < (size); y++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}

}
