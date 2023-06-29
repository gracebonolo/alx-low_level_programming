#include <ctype.h>

/**
 * cap_string - capitalizes all words in a string
 * @str: input string
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i = 0;
	int capitalize = 1;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		    || str[i] == ',' || str[i] == ';' || str[i] == '.'
		    || str[i] == '!' || str[i] == '?' || str[i] == '"'
		    || str[i] == '(' || str[i] == ')' || str[i] == '{'
		    || str[i] == '}')
		{
			capitalize = 1;
		}
		else if (capitalize && islower(str[i]))
		{
			str[i] = toupper(str[i]);
			capitalize = 0;
		}

		i++;
	}

	return (str);
}
