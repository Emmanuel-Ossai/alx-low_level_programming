#include "main.h"

/**
 * flip_bits - a C function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: n number
 * @m: m number
 *
 * Return: returns the number of bits you would need to flip
 **/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int differnce, result;
	unsigned int o, p;

	q = 0;
	result = 1;
	differnce = n ^ m;
	for (o = 0; o < (sizeof(unsigned long int) * 8); o++)
	{
		if (result == (differnce & result))
			p++;
		result <<= 1;
	}

	return (p);
}

