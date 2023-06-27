#include "main.h"

/**
 * puts_half - Prints the second half of a string.
 * @str: The string to print the second half of.
 */
void puts_half(char *str)
{
	int len = _strlen(str);
	int i, n;

	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}

	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
