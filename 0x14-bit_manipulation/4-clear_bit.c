#include "main.h"

/**
 * clear_bit - Clears a bit at a given index in a number.
 * @n: A pointer to the number.
 * @index: The index of the bit to clear.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	mask = 1 << index;
	*n = *n & ~mask;

	return (1);
}

