#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file
 * @filename: The name of the file to create
 * @text_content: The text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int fd;
	ssize_t text_len;
	ssize_t bytes_written;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		text_len = 0;
		while (text_content[text_len] != '\0')
			text_len++;

		bytes_written = write(fd, text_content, text_len);

		if (bytes_written == -1 || bytes_written != text_len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
