#include "main.h"
#include <stddef.h>

/**
 * cap_string - Capitalizes all words in a string.
 * @str: Input string.
 *
 * Return: Pointer to the resulting string.
 */
char *cap_string(char *str)
{
	if (str == NULL)
		return (NULL);

	int = 1;
	char *s = str;

	while (*s != '\0')
	{
		if (*s == ' ' || *s == '\t' || *s == '\n' ||
		    *s == ',' || *s == ';' || *s == '.' ||
		    *s == '!' || *s == '?' || *s == '"' ||
		    *s == '(' || *s == ')' || *s == '{' ||
		    *s == '}')
		{
			capitalize = 1;
		}
		else if (capitalize && islower(*s))
		{
			*s = toupper(*s);
			capitalize = 0;
		}

		s++;
	}

	return (str);
}
