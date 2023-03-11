#include <stdio.h>
#include <stdlib.h>


/**
 * main -  function that prints the minimum number
 * of coins to make change for an amount of money
 * @argc: count arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
int i, total, change, j;
int coins[] = {25, 10, 5, 2, 1};

i = total = change = j = 0;

if (argc != 2)
{
printf("Error\n");
return (1);
}

total = atoi(argv[1]);
if (total <= 0)
{
printf("0\n");
return (0);
}

while (coins[i] != '\0')

{
if (total >= coins[i])
{
j = (total / coins[i]);
change += j;
total -= coins[i] * j;
}

i++;

}

printf("%d\n", change);
return (0);
}
