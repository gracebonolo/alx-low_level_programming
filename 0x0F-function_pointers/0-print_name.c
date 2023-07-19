#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a pointer to a function.
 * @name: The name to be printed.
 * @f: A pointer to the function responsible for printing the name.
 *
 * This function takes a name and a pointer to a function that is
 * responsible for printing names. If the provided name and function
 * pointer are valid, the function calls the function pointed to by `f`
 * and passes `name` as an argument to that function, resulting in the
 * printing of the name.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
