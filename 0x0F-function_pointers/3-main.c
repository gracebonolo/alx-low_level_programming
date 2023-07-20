#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point of the program
 * @argc: The number of arguments (including program name).
 * @argv: Array of strings containing the arguments.
 *
 * Return: 0 on success, 98 on wrong number of arguments, 99 on invalid operator,
 * and 100 on division/modulo by 0 error.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	op_func = get_op_func(argv[2]);

	if (op_func == NULL)
	{
		printf("Error\n");
		return (99);
	}

	result = op_func(num1, num2);
	printf("%d\n", result);

	return (0);
}

