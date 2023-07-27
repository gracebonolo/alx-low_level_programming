#include <stdio.h>

/* Function prototype for the constructor function */
void __attribute__((constructor)) before_main(void);

/**
 * before_main - Function that runs before main.
 * It prints the desired message.
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

