#include "main.h"

/**
 * _memset - Fills a block of memory with a specific value
 * @s: Pointer to the memory block to be filled
 * @b: The value to fill the memory block with
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to the modified memory block
 *
 * Description: This function fills the first 'n' bytes of the memory block
 *		pointed to by 's' with the value 'b'. It iterates over the
 *		memory block and assigns 'b' to each byte, starting from the
 *		beginning of the block. The function assumes that the memory
 *		block is large enough to accommodate 'n' bytes and does not
 *		perform any size checks.
 */
char *_memset(char *s, char *b, unsigned int n) {
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
