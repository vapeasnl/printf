#include "main.h"
/**
* print_i - prints integer
* @args: argument to print
* Return: integer
*/
int print_i(va_list args)
{
int x = va_arg(args, int);
int n, last = x % 10, digit, exp = 1;
int  i = 1;
x = x / 10;
if (last < 0)
{
_putchar('-');
n = -n;
x = -x;
last = -last;
i++;
}
if (n > 0)
{
while (n / 10 != 0)
{
exp = exp * 10;
n = n / 10;
}
n = x;
while (exp > 0)
{
digit = n / exp;
_putchar(digit + '0');
n = n - (digit *exp);
exp = exp / 10;
i++;
}
}
_putchar(last + '0');
return (i);
}
/**
 * print_d - prints decimal
 * @args: argument to print
 * Return: integer
 */
int print_d(va_list args)
{
int x = va_arg(args, int);
int n, last = n % 10, digit;
int  i = 1;
int exp = 1;
x = x / 10;
n = x;
if (last < 0)
{
_putchar('-');
n = -n;
x = -x;
last = -last;
i++;
}
if (n > 0)
{
while (n / 10 != 0)
{
exp = exp * 10;
n = n / 10;
}
n = x;
while (exp > 0)
{
digit = n / exp;
_putchar(digit + '0');
n = n - (digit * exp);
exp = exp / 10;
i++;
}
}
_putchar(last + '0');
return (i);
}
