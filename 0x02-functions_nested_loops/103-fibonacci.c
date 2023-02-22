#include <stdio.h>

/**
 * main - C program that finds and prints the sum of
 * the even-valued terms, followed by a new line.
 * By considering the terms in the Fibonacci sequence
 * whose values do not exceed 4,000,000
 * Return: 0
 */

int main(void)
{
	unsigned long fibonacci1 = 0, fibonacci2 = 1, fibonaccisum;
	float tot_sum;

	while (1)
	{
		fibonaccisum = fibonacci1 + fibonacci2;
		if (fibonaccisum > 4000000)
			break;

		if ((fibonaccisum % 2) == 0)
			tot_sum += fibonaccisum;

		fibonacci1 = fibonacci2;
		fibonacci2 = fibonaccisum;
	}
	printf("%f\n", tot_sum);

	return (0);
}
