#include "main.h"

/**
 * create_file - a C function that creates a file.
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”, etc
 */

int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
		{
			len++;
		}
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}

	w = write(fd, text_content, len);

	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
