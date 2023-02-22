#include <stdio.h>

/**
 * main - C program that prints the first 50 Fibonacci
 * numbers, starting with 1 and 2, followed by a new line.
 * Return: 0
 */

int main(void)
{
	int count;
	unsigned long fibonacci1 = 0, fibonacci2 = 1, sum;

	for (count = 0; count < 50; count++)
	{
		sum = fibonacci1 + fibonacci2;
		printf("%lu", sum);

		fibonacci1 = fibonacci2;
		fibonacci2 = sum;

		if (count == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
