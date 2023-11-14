#include "main.h"

/**
 * xprint_extra - prints an hexgecimal number.
 * @args: arguments.
 * Return: sum.
 */
int xprint_extra(unsigned long int args)
{
	long int i;
	long int *arr;
	long int sum = 0;
	unsigned long int temp = args;

	while (args / 16 != 0)
	{
		args /= 16;
		sum++;
	}
	sum++;
	arr = malloc(sum * sizeof(long int));

	for (i = 0; i < sum; i++)
	{
		arr[i] = temp % 16;
		temp = temp / 16;
	}
	for (i = sum - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (sum);
}
