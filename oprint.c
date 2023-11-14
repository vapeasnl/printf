#include "main.h"

/**
 * oprint - prints an octal number.
 * @args: arguments.
 * Return: sum.
 */
int oprint(va_list args)
{
	int i;
	int *arr;
	int sum = 0;
	unsigned int n = va_arg(args, unsigned int);
	unsigned int tmp = n;

	while (n / 8 != 0)
	{
		n /= 8;
		sum++;
	}
	sum++;
	arr = malloc(sum * sizeof(int));

	for (i = 0; i < sum; i++)
	{
		arr[i] = tmp % 8;
		tmp /= 8;
	}
	for (i = sum - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (sum);
}
