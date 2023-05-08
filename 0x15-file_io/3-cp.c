#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * arg_chk - a C function that checks for correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */

void arg_chk(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * rd_chk - a C function that checks that file_from exists and can also be read
 * @che: if true of false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */

void rd_chk(ssize_t che, char *file, int fd_from, int fd_to)
{
	if (che == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}

/**
 * rw_chk - a C function that checks that file_to can be created
 * @che: if true of false
 * @file: file_to name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */

void rw_chk(ssize_t che, char *file, int fd_from, int fd_to)
{
	if (che == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}

/**
 * cl_chk - a C function that checks that file van be closed
 * @che: if true or false
 * @fd: file descriptor
 *
 * Return: void
 */

void cl_chk(int che, int fd)
{
	if (che == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * main - a C program that copies the content of a file to another file.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, close_to, close_from;
	ssize_t lenr, lenw;
	char buffer[1024];
	mode_t file_perm;

	arg_chk(argc);
	fd_from = open(argv[1], O_RDONLY);
	rd_chk((ssize_t)fd_from, argv[1], -1, -1);
	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);
	rw_chk((ssize_t)fd_to, argv[2], fd_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		lenr = read(fd_from, buffer, 1024);
		rd_chk(lenr, argv[1], fd_from, fd_to);
		lenw = write(fd_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;
		rw_chk(lenw, argv[2], fd_from, fd_to);
	}
	close_to = close(fd_to);
	close_from = close(fd_from);
	cl_chk(close_to, fd_to);
	cl_chk(close_from, fd_from);
	return (0);
}
