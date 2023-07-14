#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the argument count
 * @av: the argument vector
 *
 * Return: pointer to a new string containing concatenated arguments,
 *         or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len, total_len = 0;
	int arg_count = ac;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
		len = strlen(av[i]);
		total_len += len;
	}

	total_len += arg_count - 1; /* Account for newlines */

	/* Allocate memory for the concatenated string */
	str = malloc((total_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy each argument to the concatenated string */
	len = 0;
	for (i = 0; i < arg_count; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[len] = av[i][j];
			len++;
		}
		if (i != arg_count - 1)
		{
			str[len] = '\n'; /* Add newline after each argument */
			len++;
		}
	}

	str[len] = '\0'; /* Add null terminator at the end */
	return (str);
}
