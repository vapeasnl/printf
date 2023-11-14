#include "main.h"

/**
 * xprint - prints an hexgecimal number.
 * @args: arguments.
 * Return: sum.
 */
int xprint(va_list args)
{
	int i;
	int *arr;
	int sum = 0;
	unsigned int n = va_arg(args, unsigned int);
	unsigned int tmp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		sum++;
	}
	sum++;
	arr = malloc(sum * sizeof(int));

	for (i = 0; i < sum; i++)
	{
		arr[i] = tmp % 16;
		tmp /= 16;
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
