#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * _strlen - Computes the length of a string.
 * @s: The string to compute the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, close_result;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_result = write(file_descriptor, text_content, _strlen(text_content));

		if (write_result == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close_result = close(file_descriptor);

	if (close_result == -1)
		return (-1);

	return (1);
}

