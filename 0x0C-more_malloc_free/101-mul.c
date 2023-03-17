#include "main.h"
#include <stdlib.h>
#include <stdio.h>


#define ERR_MSG "Error"


/**
 * is_digit - to check if a string contains a non-digit char
 * @s: string to be checked
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */

int is_digit(char *s)

{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - function that returns the length of a string
 * @s: string to check
 *
 * Return: length of the string
 */

int _strlen(char *s)

{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


/**
 * errors - handles errors for main
 */

void errors(void)

{
	printf("Error\n");
	exit(98);
}


/**
 * main -function that multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */

int main(int argc, char *argv[])

{
	char *s1, *s2;

	int s1_len, s2_len, len, i, carry, digit1, digit2, *s, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	len = s1_len + s2_len + 1;
	s = malloc(sizeof(int) * len);
	if (!s)
		return (1);
	for (i = 0; i <= s1_len + s2_len; i++)
		s[i] = 0;
	for (s1_len = s1_len - 1; s1_len >= 0; s1_len--)
	{	digit1 = s1[s1_len] - '0';
		carry = 0;
		for (s2_len = _strlen(s2) - 1; s2_len >= 0; s2_len--)
		{
			digit2 = s2[s2_len] - '0';
			carry += s[s1_len + s2_len  + 1] + (digit1 * digit2);
			s[s1_len + s2_len + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			s[s1_len + s2_len + 1] += carry;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (s[i])
			a = 1;
		if (a)
			_putchar(s[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
