#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table
 * @n: The number to generate the times table
 *
 * Return: void
 */
void print_times_table(int n)
{
    if (n < 0 || n > 15)
        return;

    int i, j, result;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            result = i * j;
            if (j == 0)
                printf("%d", result);
            else if (result < 10)
                printf(", %3d", result);
            else if (result < 100)
                printf(", %2d", result);
            else
                printf(", %d", result);
        }
        printf("\n");
    }
}
