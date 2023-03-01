#include "main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: input string
 * @src: input string appended to @dest
 *
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
        int i = 0, int j = 0;

        while (dest[i++])
                j++;

        for (i = 0; src[i]; i++)
                dest[j++] = src[i];

        return (dest);
}
