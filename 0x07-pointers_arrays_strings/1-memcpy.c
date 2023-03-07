#include "main.h"
/**
 *_memcpy - function that copies memory area
 *@dest: copied to this memory area
 *@src: copied from this memory area
 *@n: n bytes from memory area @src
 *
 *Return: pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
