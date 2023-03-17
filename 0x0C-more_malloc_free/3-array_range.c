#include "main.h"
#include <stdlib.h>

/**
 * array_range - a C function that creates an array of integers.
 * @min: the minimum array value
 * @max: the maximum array value
 *
 * Return: a pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *ptr;
	int n, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (n = 0; min <= max; n++)
		ptr[n] = min++;

	return (ptr);
}
