#include "main.h"

/**
 * print_alphabet - C program that prints the alphabet, in lowercase,
 * followed by a new line.
 */

void print_alphabet(void)

{
	char letter a;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');

}
