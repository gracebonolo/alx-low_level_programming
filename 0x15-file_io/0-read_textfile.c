#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - Reads a specified number of letters from a text file and prints them to the standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. If an error occurs, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t bytesRead, bytesWritten;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Filename is NULL\n");
		return (0);
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (0);
	}

	buffer = (char *)malloc(letters + 1); /* Allocate space for the buffer */
	if (buffer == NULL)
	{
		perror("Error allocating buffer");
		fclose(file);
		return (0);
	}

	bytesRead = fread(buffer, 1, letters, file);
	if (bytesRead == -1)
	{
		perror("Error reading file");
		free(buffer);
		fclose(file);
		return (0);
	}

	buffer[bytesRead] = '\0'; /* Null-terminate the string */

	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten == -1 || (size_t)bytesWritten != (size_t)bytesRead)
	{
		perror("Error writing to stdout");
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);

	return (bytesRead);
}

