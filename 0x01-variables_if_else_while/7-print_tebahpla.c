#include <stdio.h>

/**
 * main - a C program that prints the lowercase alphabet
 * in reverse order
 * Return: 0
 */

int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
		putchar(letter);

	putchar('\n');

	return (0);
}
