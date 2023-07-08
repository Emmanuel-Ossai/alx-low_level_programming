#include "hash_tables.h"

/**
 * hash_djb2 - a C function that implementation of the djb2 algorithm.
 * @str: String used to generate the hash value.
 *
 * Return: The hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}
