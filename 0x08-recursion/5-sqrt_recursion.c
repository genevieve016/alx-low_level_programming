#include "main.h"

int final_sqrt_recursion(int n, int i);

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: number
 *
 * Return: natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (final_sqrt_recursion(n, 0));
}

/**
 * final_sqrt_recursion - recursive function to find the natural square root
 * @n: number to use
 * @i: iterator
 *
 * Return: result of natural square root
 */
int final_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (final_sqrt_recursion(n, i + 1));
}
