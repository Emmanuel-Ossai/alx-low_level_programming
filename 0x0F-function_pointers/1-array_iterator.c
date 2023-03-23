#include "function_pointers.h"

/**
 * array_iterator - a C function that executes a function given
 * as a parameter on each element of an array.
 * @array: the array
 * @size: the size of the array
 * @action: a pointer to the function to be used
 *
 * Return: void
 */


void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array && action)
	{
		i = 0;
		while (i < size)
		{
			action(array[i]);
			i++;
		}
	}
}
