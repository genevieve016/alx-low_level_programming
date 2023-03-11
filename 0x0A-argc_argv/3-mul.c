#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 * main -  print the result of the multiplication of two numbers
 * @argc: count arguments
 * @argv: array of arguments
 *
 * Return: 0 if true, else return 1
 */

int main(int argc, char *argv[])
{
int a, b;
if (argc == 3)
{
a = atoi(argv[1]);
b = atoi(argv[2]);
printf("%d\n", a *b);
return (0);
}
printf("Error\n");
return (1);
}
