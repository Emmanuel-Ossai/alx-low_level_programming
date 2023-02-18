#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - C program that prints the size of various will
 * assign a random number to the variable n each time it is executed
 * Return: 0
*/

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf(n);

	if (n > 0)
		printf("is positive\n");

	else if (n == 0)
		printf("is zero\n");

	else if (n < 0)
		printf("is negative\n");

	return (0);
}
