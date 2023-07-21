#ifndef DOG_H
#define DOG_H

#include <string.h>

/**
 * struct dog - Structure representing a dog's basic info
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
typedef struct dog dog_t;
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);

#endif
