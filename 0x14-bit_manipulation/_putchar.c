#include "main.h"
#include <unistd.h>

/**
 * _putchar - a C function that writes the character c to stdout
 * @c: The character to be written
 *
 * Return: On success 1.
 * On error, -1 is return
 **/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
