#include <stdio.h>
#include <stdlib.h>

/**
 * main - calculates the minimum number of coins to make change
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int amount, coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amount = atoi(argv[1]);

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	while (amount >= 25)
	{
		coins++;
		amount -= 25;
	}

	while (amount >= 10)
	{
		coins++;
		amount -= 10;
	}

	while (amount >= 5)
	{
		coins++;
		amount -= 5;
	}

	while (amount >= 2)
	{
		coins++;
		amount -= 2;
	}

	while (amount >= 1)
	{
		coins++;
		amount -= 1;
	}

	printf("%d\n", coins);

	return (0);
}
