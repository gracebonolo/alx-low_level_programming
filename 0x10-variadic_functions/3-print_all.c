#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - Print a character.
 * @arg: The argument to be printed.
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_integer - Print an integer.
 * @arg: The argument to be printed.
 */
void print_integer(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - Print a float.
 * @arg: The argument to be printed.
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - Print a string.
 * @arg: The argument to be printed.
 */
void print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0, j = 0;
	char *separator = "";
	print_fn print_funcs[] = {
		{'c', print_char},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (print_funcs[j].format)
		{
			if (format[i] == print_funcs[j].format)
			{
				printf("%s", separator);
				print_funcs[j].printer(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
