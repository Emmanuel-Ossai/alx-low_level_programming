#include "variadic_functions.h"

/**
 * print_strings - a C function that prints strings,
 * followed by a new line.
 * @n: the number of strings passed to the function
 * @separator: the string to be printed between strings
 *
 * Return: 0
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	if (separator == NULL)
		separator = "";

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(nil)";
		printf("%s", str);
		if (i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
