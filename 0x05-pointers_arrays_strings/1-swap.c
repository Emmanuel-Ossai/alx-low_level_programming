#include "main.h"

/**
 * swap_int - a C function that swaps the values of two integers (a & b)
 * @a: int to be swapped
 * @b: int to be swapped
 *
 * Return: 0
 */

void swap_int(int *a, int *b)
{
	int y;

	y  = *a;
	*a = *b;
	*b = y;
}
