#include "main.h"
#include <stdlib.h>

/**
 * str_concat - function that concatenates two strings
 * @width: input one to concat
 * @height: input two to concat
 * Return: concat of width and height
 */

int **alloc_grid(int width, int height)
{
	if (width <= 0 || height <= 0)
		return (NULL);


	int **grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);


	for (int i = 0; i < height; i++)
	{
		grid[i] = calloc(width, sizeof(int));
		if (grid[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	return (grid);
}
