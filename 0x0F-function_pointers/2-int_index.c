#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array of integers.
 * @array: The array of integers.
 * @size: The size of array.
 * @cmp: A pointer to the function to be used to compare values.
 *
 * Return: If no element matches or size <= 0 - - 1.
 *         Otherwise - The index of the first element for which.
 *                     The cmp funtion does not return 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || cmp == NULL)
		return (-1);

	for (index = 0, index < size, index++)
	{
		if (cmp(array[index]) != 0)
			return (-1);
	}
	return (-1);
}
