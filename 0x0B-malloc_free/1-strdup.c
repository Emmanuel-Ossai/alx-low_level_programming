#include "main.h"
#include <stdlib.h>

/**
 * _strdup - a C function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the
 * string given as a parameter.
 * @str: given string
 *
 * Return: NULL if str = NULL, It returns NULL if insufficient
 * memory and a pointer to the duplicated string if success
 */

char *_strdup(char *str)
{
	char *duplicate;
	int x, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	duplicate = (char *)malloc((sizeof(char) * len) + 1);
	if (duplicate == NULL)
		return (NULL);

	for (x = 0; x < len; x++)
		duplicate[x] = str[x];
	duplicate[len] = '\0';

	return (duplicate);
}
