#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - a C program that generates a key for crackme5.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	add = 0;

	for (size_t x = 0; x < len; x++)
		add += argv[1][x];
	p[1] = l[(add ^ 79) & 63];
	unsigned int k = 1;

	for (size_t x = 0; x < len; x++)
		k *= argv[1][x];
	p[2] = l[(k ^ 85) & 63];

	k = argv[1][0];
	for (size_t x = 0; x < len; x++)
	{
		if (argv[1][x] >= (char)k)
			k = argv[1][x];
	}
	srand(k ^ 14);
	p[3] = l[rand() & 63];
	k = 0;
	for (size_t x = 0; x < len; x++)
		k += argv[1][x] * argv[1][x];
	p[4] = l[(k ^ 239) & 63];
	k = 0;
	for (size_t x = 0; (char)x < argv[1][0]; x++)
		k = rand();
	p[5] = l[(k ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
