#include "main.h"

/**
 * get_endianness - a C function that checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 **/

int get_endianness(void)
{
	int x;
	char *c;

	x = 1;
	c = (char *)&x;

	return (*c);
}
