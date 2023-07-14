#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: Pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
        int a = 0;

        while (dest[a] != '\0')
        {
                a++;
        }

        int b = 0;
        while (src[b] != '\0')
        {
                dest[a] = src[b];
                a++;
                b++;
        }

        dest[a] = '\0';
        return (dest);
}
