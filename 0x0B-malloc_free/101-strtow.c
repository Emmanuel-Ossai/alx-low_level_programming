#include "main.h"
#include <stdlib.h>

/**
 * strtow - a C function that splits a string into words.
 * @str: the string
 *
 * Return: a pointer to an array of strings
 */


char **strtow(char *str)
{
	int x, flag, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	x = flag = len = 0;
	while (str[x])
	{
		if (flag == 0 && str[x] != ' ')
			flag = 1;
		if (x > 0 && str[x] == ' ' && str[x - 1] != ' ')
		{
			flag = 0;
			len++;
		}
		x++;
	}

	len += flag == 1 ? 1 : 0;
	if (len == 0)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);

	util(words, str);
	words[len] = NULL;
	return (words);
}


/**
 * util - a C function that fetches words into array.
 * @str: the string
 * @words: string array
 *
 * Return: 0
 */

void util(char **words, char *str)
{
	int x, y, start, flag;

	x = y = flag = 0;
	while (str[x])
	{
		if (flag == 0 && str[x] != ' ')
		{
			start = x;
			flag = 1;
		}

		if (x > 0 && str[x] == ' ' && str[x - 1] != ' ')
		{
			create_word(words, str, start, x, y);
			y++;
			flag = 0;
		}

		x++;
	}

	if (flag == 1)
		create_word(words, str, start, x, y);
}


/**
 * create_word - a C function that creates and inserts words into array.
 * @str: the string
 * @words: string array
 * @start: start index of the word
 * @end: stop index of the word
 * @index: index of the array
 *
 * Return: 0
 */


void create_word(char **words, char *str, int start, int end, int index)
{
	int x, y;

	x = end - start;
	words[index] = (char *)malloc(sizeof(char) * (x + 1));

	for (y = 0; start < end; start++, y++)
		words[index][y] = str[start];
	words[index][y] = '\0';
}
