#include "main.h"
/**
 * uprint - prints integer
 * @val: argument to print
 * Return: integer
 */
int uprint(va_list val)
{
	unsigned int n = va_arg(val, unsigned int);
	int num, end = n % 10, d, ep = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (end < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		end = -end;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			ep = ep * 10;
			num = num / 10;
		}
		num = n;
		while (ep > 0)
		{
			d = num / ep;
			_putchar(d + '0');
			num = num - (d * ep);
			ep = ep / 10;
			i++;
		}
	}
	_putchar(end + '0');

	return (i);
}
