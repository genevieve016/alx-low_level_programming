#include "main.h"
#include <unistd.h>
/**
 * _putchar - c is written to stdout
 * @c: Character to be printed
 *
 * Return: Successful 1.
 * If unsuccessful, -1 is returned, and errno is changed accordingly.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
