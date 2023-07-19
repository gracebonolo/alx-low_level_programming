#include <stdio.h>

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: The array to be iterated.
 * @size: The number of elements in the array.
 * @action: A pointer to the function to be executed on each element.
 *
 * This function takes an integer array, its size, and a pointer to a function.
 * It iterates over each element in the array and executes the function on it.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
