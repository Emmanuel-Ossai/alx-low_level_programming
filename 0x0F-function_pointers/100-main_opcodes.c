#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - a C program that prints the opcodes of
 * its own main function.
 * @a: the address of the main function
 * @n: the number of bytes to print
 *
 * Return: 0
 */

void print_opcodes(char *a, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		printf("%.2hhx", a[x]);
		if (x < n - 1)
			printf(" ");
	}
	printf("\n");

}

/**
 * main - a C function that prints the opcodes of
 * its own main function
 * @argc: the argument conunts
 * @argv: the argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, n);
	return (0);
}
