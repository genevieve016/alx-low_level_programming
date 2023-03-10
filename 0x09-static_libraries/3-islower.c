#include "main.h"

/**
 * _islower - checks for lowercase character
 * @c: char that will be checked
 * Return: 1 if char is lowercase, if not, return 0.
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
