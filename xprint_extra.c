#include "main.h"

/**
 * xprint_extra - prints an hexgecimal number.
 * @args: arguments.
 * Return: sum.
 */
int xprint_extra(va_list args)
{
	int i;
	int *arr;
	int sum = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int tmp = num;

	while (num / 16 != 0)
	{
		num /= 16;
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
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (sum);
}
