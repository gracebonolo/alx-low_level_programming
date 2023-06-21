#include "main.h"

/**
 * _putchar - custom function to print a single character
 * @c: the character to be printed
 *
 * Return: On success, returns the character that was printed.
 *         On error, returns -1.
 */
int _putchar(char c)
{
	return (putchar(c));
}

/**
 * main - prints _putchar and a new line
 *
 * Return: Always 0
 */
int main(void)
{
	_putchar('_');
	_putchar('p');
	_putchar('u');
	_putchar('t');
	_putchar('c');
	_putchar('h');
	_putchar('a');
	_putchar('r');
	_putchar('\n');

	return (0);
}
