#include <stdio.h>

int main(int argc, char *argv[])
{
    char *str;

    str = argstostr(argc, argv);
    if (str == NULL)
    {
	   printf("Failed to allocate memory\n");
	    return 1;
    }

    printf("%s\n", str);
    free(str);
    return (0);
}
