#include "main.h"
/**
 * iprint - print int
 * @args: print arg
 * Return: number of characters printed
*/

int iprint(va_list args)
{
	int num = va_arg(args, int);
	int num1, end = num % 10, digit, j = 1;
	int  i = 1;

	num /= 10;
	num1 = num;

	if (end < 0)
	{
		_putchar('-');
		num1 = -num1;
		num = -num;
		end = -end;
		i++;
	}
	if (num1 > 0)
	{
		while (num1 / 10 != 0)
		{
			j *= 10;
			num1 /= 10;
		}
		num1 = num;
		while (j > 0)
		{
			digit = num1 / j;
			_putchar(digit + '0');
			num1 = num1 - (digit * j);
			j /= 10;
			i++;
		}
	}
	_putchar(end + '0');
	return (i);
}

