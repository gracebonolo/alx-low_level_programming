#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome_recursive - checks if a substring is a palindrome recursively
 * @s: the string to check
 * @start: starting index of the substring
 * @end: ending index of the substring
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] == s[end])
		return (is_palindrome_recursive(s, start + 1, end - 1));

	return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	if (len <= 1)
		return (1);

	return (is_palindrome_recursive(s, 0, len - 1));
}
