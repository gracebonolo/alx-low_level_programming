#include <stdio.h>

/**
 * main - prints the alphabet in reverse order in lowercase
 * Return: Always 0
 */
int main(void)
{
	char le;

	for (le = 'z'; le >= 'a'; le--)
		putchar(le);

	putchar('\n');

	return (0);
}
