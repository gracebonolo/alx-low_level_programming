#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int count;
	unsigned long fib1 = 1, fib2 = 2, next;

	printf("%lu, %lu", fib1, fib2);

	for (count = 2; count < 98; count++)
	{
		next = fib1 + fib2;
		printf(", %lu", next);
		fib1 = fib2;
		fib2 = next;
	}

	printf("\n");
	return (0);
}

