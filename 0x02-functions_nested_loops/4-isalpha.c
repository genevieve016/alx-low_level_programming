#include "main.h"

/**
 * _isalpha - function that checks for alphabetic characters
 * @c: character to be checked by function
 * Return: 1 if c is a letter, else, return 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
