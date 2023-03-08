#include "main.h"

int final_prime(int n, int i);

/**
 * is_prime_number - function that determines if an integer
 * is a prime number or not
 * @n: input int
 *
 * Return: 1 if n is a prime number, else 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (final_prime(n, n - 1));
}

/**
 * final_prime - recirsive function that calculates if a number is prime
 * @n: input number
 * @i: iterator
 *
 * Return: 1 if n is prime number, else 0
 */
int final_prime(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (final_prime(n, i - 1));
}
