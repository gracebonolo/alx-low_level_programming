#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long n1 = 1, n2 = 2, next;
	unsigned long sum = 0;

	while (n1 <= 4000000)
	{
		if (n1 % 2 == 0)
			sum += n1;

		next = n1 + n2;
		n1 = n2;
		n2 = next;
	}

	printf("%lu\n", sum);

	return (0);
}

