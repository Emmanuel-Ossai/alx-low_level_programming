#include "main.h"

/**
 * reverse_array - a C function that reverses the content
 * of an array of integers.
 * @a: an array of integers
 * @n: the number of elements of the array to swap
 *
 * Return: nothing
 */

void reverse_array(int *a, int n)
{
int i, j;

for (i = 0; (i < (n - 1) / 2); i++)
	{
	j = a[i];
	a[i] = a[n - 1 - i];
	a[n - 1 - i] = j;
	}
}
