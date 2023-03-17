#include "main.h"
#include <stdlib.h>

/**
 * *string_nconcat - function that concatenates two strings
 * @s1: string to allocate to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to allocate to s1
 *
 * Return: pointer to the newly allocated space
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s = NULL;
	unsigned int s1_len = 0, s2_len = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[s1_len] != '\0')
	{
		s1_len++;
	}
	while (s2[s2_len] != '\0')
	{
		s2_len++;
	}
	if (n >= s2_len)
	{
		n = s2_len;
	}

	s = (char *) malloc(sizeof(char) * (s1_len + n + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	for (unsigned int i = 0; i < s1_len; i++)
	{
		s[i] = s1[i];
	}
	for (unsigned int i = 0; i < n; i++)
	{
		s[s1_len + i] = s2[i];
	}

	s[s1_len + n] = '\0';
	return (s);
}
