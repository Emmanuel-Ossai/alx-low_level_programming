#include <stdio.h>

/**
 * main - a C program a program that prints the alphabet in lowercase,
 * followed by a new line
 * Return: Always 0.
*/

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	putchar('\n');

	return (0);
}
