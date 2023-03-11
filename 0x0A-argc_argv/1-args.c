#include "stdio.h"

/**
 * main - a C program that prints its name, followed by a new line.
 * @argc: the argument count
 * @argv: the argument arry
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
