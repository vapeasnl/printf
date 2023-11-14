#include "main.h"

/**
 * bprint - prints unsigned int converted to binary
 * @b: arg
 * Return: binary num
 */
int bprint(va_list b)
{
	unsigned int num = va_arg(b, unsigned int);
	int c = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	unsigned int temp = num;
	int sum = 0;
	while (temp > 0)
	{
		temp /= 2;
		sum++;
	}

	unsigned int bitmask = 1U << (sum - 1);

	while (bitmask > 0)
	{
		_putchar((num & bitmask) ? '1' : '0');
		c++;
		bitmask >>= 1;
	}

	return (c);
}
