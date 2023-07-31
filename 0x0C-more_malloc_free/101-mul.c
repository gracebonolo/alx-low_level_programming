#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_error_and_exit - Prints an error message and exits the program with
 *                        a status of 98.
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments (including the program name)
 * @argv: An array of pointers to the command-line arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, j;
	unsigned long int result;

	if (argc != 3)
		print_error_and_exit();

	for (i = 1; i < 3; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!_isdigit(argv[i][j]))
				print_error_and_exit();
		}
	}

	result = strtoul(argv[1], NULL, 10) * strtoul(argv[2], NULL, 10);
	printf("%lu\n", result);

	return (0);
}

