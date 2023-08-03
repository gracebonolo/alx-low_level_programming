#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is an invalid char or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
		{
			result <<= 1; /* Left shift by 1 to add a 0 bit */
		}
		else if (b[i] == '1')
		{
			result <<= 1; /* Left shift by 1 to add a 0 bit */
			result |= 1; /* Set the least significant bit to 1 */
		}
		else
		{
			return (0);  /* Invalid char found, return 0 */
		}
	}

	return (result);
}

