#include "main.h"

/**
 * _strncat - concatenate two strings using at most n bytes from @src
 * @dest: input (resulting) string
 * @src: input string
 * @n: n bytes from @src
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;
{
        int i = 0, int j = 0;

        while (dest[i++])
                j++;

        for (i = 0; src[i] && i < n; i++)
                dest[j++] = src[i];

        return (dest);
}
