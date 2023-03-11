#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * main - a C program that multiplies two numbers.
 * @argc: the argument count
 * @argv: the argument arry
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int x, y;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	printf("%d\n", x * y);

	return (0);
}
