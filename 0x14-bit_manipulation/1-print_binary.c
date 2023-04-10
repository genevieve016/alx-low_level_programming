#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: binary number to print
 */

void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current_bit;

	for (i = 63; i >= 0; i--)
	{
		current_bit = n >> i;

		if (current_bit & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
