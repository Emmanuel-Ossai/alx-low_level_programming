#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * op_add - operator add
 * @a: first integer
 * @b: second integer
 *
 * Return: 0
 */

int op_add(int a, int b)
{
	return (a + b);
}


/**
 * op_sub - operator subbstraction
 * @a: first integer
 * @b: second integer
 *
 * Return: 0
 */


int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - operator multiplication
 * @a: first integer
 * @b: second integer
 *
 * Return: 0
 */


int op_mul(int a, int b)
{
	return (a * b);
}


/**
 * op_div - operator division
 * @a: first integer
 * @b: second integer
 *
 * Return: 0
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - operator mod
 * @a: first integer
 * @b: second integer
 *
 * Return: 0
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
