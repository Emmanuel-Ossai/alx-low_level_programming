#include <unistd.h>

/**
 * _putchar - a C function that writes the character c to stdout.
 * @c: character to be printed
 *
 * Return: 1 if successful and -1 if there is an error,
 * and errno is set appropriately
 */

int _putchar(char c)

{
	return (write(1, &c, 1));

}
