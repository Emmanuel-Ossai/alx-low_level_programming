#include <stdio.h>
#include "main.h"
/**
 * main - a C program that prints its name, followed by a new line.
 * @argc: the argument count
 * @argv: the argument arry
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
