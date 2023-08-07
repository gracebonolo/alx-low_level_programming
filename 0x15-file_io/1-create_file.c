#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - Creates a file and writes the given text content to it.
 * @filename: The name of the file to create.
 * @text_content: The NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, text_len, write_status;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	text_len = 0;
	while (text_content[text_len])
		text_len++;

	write_status = write(fd, text_content, text_len);
	close(fd);

	if (write_status != text_len)
		return (-1);

	return (1);
}

