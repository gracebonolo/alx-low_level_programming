#include "main.h"

/**
 * _strncpy - Copies a string
 * @dest: Destination buffer
 * @src: Source string
 * @n: Maximum number of characters to copy
 * Return: Pointer to destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] - src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}
