#include "main.h"
#include <stdlib.h>

/**
 * *_realloc - function reallocates a memory block using malloc and free
 * @ptr: pointer to the previous memory
 * @old_size: size of the allocated memory for @ptr
 * @new_size: new size of new memory block
 *
 * Return: pointer to the newly allocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			exit(1);
		}
		return (new_ptr);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{ exit(1);
	}
	if (new_size < old_size)
	{
		for (unsigned int i = 0; i < new_size; i++)
		{
			*((char *) new_ptr + i) = *((char *) ptr + i);
		}
	}
	else
	{
		for (unsigned int i = 0; i < old_size; i++)
		{
			*((char *) new_ptr + i) = *((char *) ptr + i);
		}
	}
	free(ptr);
	return (new_ptr);
}
