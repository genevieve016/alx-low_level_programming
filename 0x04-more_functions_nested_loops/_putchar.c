#include "main.h"
#include <unistd.h>
/**
 * _putchar - function that writes the character c to stdout
 * @c: character to print
 *
 * Return: 1 if successful.
 * Otherwise, -1 is returned, and errno is set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
