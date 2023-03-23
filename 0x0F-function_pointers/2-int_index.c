#include "function_pointers.h"

/**
 * int_index - a C function that searches for an integer.
 * @array: the array
 * @size: the number of elements in the array array
 * @cmp: a pointer to the function to be used to compare values
 *
 * Return: the index of the first element for which the cmp
 * function does not return 0
 */


int int_index(int *array, int size, int (*cmp)(int))
{
	int y = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (y < size)
			{
				if (cmp(array[y]))
					return (y);

				y++;
			}
		}
	}

	return (-1);
}
