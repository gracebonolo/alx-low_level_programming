#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function
 *        c: char
 *        i: integer
 *        f: float
 *        s: char * (if the string is NULL, print (nil) instead)
 * Any other char should be ignored.
 * Return: Nothing (void)
 */
void print_all(const char *const format, ...)
{
	va_list args;
	char *str;
	int num;
	char ch;
	float fl;
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			ch = va_arg(args, int);
			printf("%c", ch);
			break;
		case 'i':
			num = va_arg(args, int);
			printf("%d", num);
			break;
		case 'f':
			fl = va_arg(args, double); // float arguments are promoted to double
			printf("%f", fl);
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
			break;
		default:
			break;
		}

		if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
			printf(", ");

		i++;
	}

	va_end(args);
	printf("\n");
}

