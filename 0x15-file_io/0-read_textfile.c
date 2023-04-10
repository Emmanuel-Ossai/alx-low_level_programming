#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - a C function that reads a text file and
 * prints it to the POSIX standard output.
 * @filename: pointer to the name of the file
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	char *buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	ssize_t o = open(filename, O_RDONLY);

	if (o == -1)
	{
		free(buffer);
		return (0);
	}

	ssize_t r = read(o, buffer, letters);

	if (r == -1)
	{
		free(buffer);
		close(o);
		return (0);
	}

	ssize_t w = write(STDOUT_FILENO, buffer, r);

	if (w == -1 || w != r)
	{
		free(buffer);
		close(o);
		return (0);
	}

	free(buffer);
	close(o);
	return (w);
}
