#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - function that concatenates two strings
 * @s1: input one to concat
 * @s2: input two to concat
 * Return: concat of s1 and s2
 */

char *str_concat(char *s1, char *s2)
{
	int i, j;
	char *concat;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = j = 0;
	while (s1[i])
		i++;

	while (s2[j])
		j++;

	concat = malloc(sizeof(char) * (i + j + 1));

	if (concat == NULL)
		return (NULL);

	i = j = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}

	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';

	return (concat);
}
