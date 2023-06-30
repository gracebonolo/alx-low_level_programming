#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @str: Input string.
 *
 * Return: Pointer to the resulting string.
 */
char *rot13(char *str)
{
	char *ptr = str;
	char *rot13_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_encoded = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;

	while (*ptr != '\0')
	{
		i = 0;
		while (rot13_chars[i] != '\0')
		{
			if (*ptr == rot13_chars[i])
			{
				*ptr = rot13_encoded[i];
				break;
			}
			i++;
		}
		ptr++;
	}

	return (str);
}
