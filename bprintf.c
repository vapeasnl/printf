#include "main.h"
/**
 * bprint - prints int converted to binary
 * @b: arg
 * Return: binary num
 */
int bprint(va_list b)
{
	unsigned int sum, j, i, l, m, num;
	int c = 0;

	m = va_arg(b, unsigned int);
	if (m)
	{
		num = m;
		while (num)
		{
			num /= 2;
			sum++;
		}
		j = 1;
		i = 1;
		while (i <= sum - 1)
		{
			j *= 2;
			i++;
		}
		i = 1;
		while (i <= sum)
		{
			l = num / j;
			_putchar(l + '0');
			c++;
			num -= l * j;
			j /= 2;
			i++;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (c);
}
