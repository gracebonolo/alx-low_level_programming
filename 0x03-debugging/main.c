#include <stdio.h>
#include "main.h"

/**
 * main - Prints the largest of 3 integers
 *
 * Return: Always 0
 */
int main(void)
{
	int a, b, c;
	int largest;

	a = 972;
	b = -98;
	c = 0;

	largest = largest_number(a, b, c);

	printf("The integers are: %d, %d, %d\n", a, b, c);
	printf("The largest integer is: %d\n", largest);

	return (0);
}
