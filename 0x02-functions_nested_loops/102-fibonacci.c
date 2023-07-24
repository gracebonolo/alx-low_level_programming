#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int count;
	unsigned long n1 = 1, n2 = 2, next;

	printf("%lu, %lu", n1, n2);

	for (count = 2; count < 50; count++)
	{
		next = n1 + n2;
		printf(", %lu", next);

		n1 = n2;
		n2 = next;
	}

	printf("\n");

	return (0);
}

