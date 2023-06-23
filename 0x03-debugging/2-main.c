#include <stdio.h>
#include "main.h"

/**
 * largest_number - Finds the largest of three integers
 * @a: First integer
 * @b: Second integer
 * @c: Third integer
 *
 * Return: The largest of the three integers
 */
int largest_number(int a, int b, int c)
{
	int largest = a;

	if (b > largest)
		largest = b;
	if (c > largest)
		largest = c;

	return (largest);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a, b, c;
	int largest;

	a = 972;
	b = -98;
	c = 0;

	largest = largest_number(a, b, c);

	printf("%d is the largest number\n", largest);

	return (0);
}
