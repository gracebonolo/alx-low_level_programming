#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created hash table,
 *         or NULL if something went wrong.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;
	unsigned long int i;

	/* Allocate memory for the hash table structure */
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);

	/* Allocate memory for the array of pointers */
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table); /* Free the hash table structure on failure */
		return (NULL);
	}

	new_table->size = size;

	/* Initialize each element of the array to NULL */
	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	return (new_table);
}

/**
 * free_hash_table - Frees the allocated memory for the hash table.
 * @ht: The hash table to be freed.
 *
 * Return: void
 */

void free_hash_table(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *temp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			temp = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = temp;
		}
	}

	free(ht->array);
	free(ht);
}

/**
 * main - Entry point.
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise.
 */

int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	if (ht == NULL)
		return (EXIT_FAILURE);

	/* Perform operations with the hash table */

	/* Free the allocated memory for the hash table when done */
	free_hash_table(ht);

	return (EXIT_SUCCESS);
}

