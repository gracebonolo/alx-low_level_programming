/**
 * largest_number - Returns the largest of 3 numbers
 * @a: First integer
 * @b: Second integer
 * @c: Third integer
 *
 * Return: Largest number
 */
int largest_number(int a, int b, int c)
{
	int largest;

	largest = a;

	if (b > largest)
	{
		largest = b;
	}

	if (c > largest)
	{
		largest = c;
	}

	return (largest);
}
