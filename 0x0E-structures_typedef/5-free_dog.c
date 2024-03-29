#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - a C function that frees dogs.
 * @d: pointer to dog to be freed
 *
 * Return: 0
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
