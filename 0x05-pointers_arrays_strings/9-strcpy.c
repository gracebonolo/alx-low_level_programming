#include "main.h"

/**
 * _strcpy - Copies the string pointed to by src
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 *
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *dest, const char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];

        dest[i] = '\0';

        return (dest);
}
