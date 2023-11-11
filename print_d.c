#include "main.h"
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
// Handle negative numbers
if (last < 0)
{
_putchar('-');
n = -n;
x = -x;
last = -last;
i++;
}
// Process and print each digit
if (n > 0)
{
// Determine the highest decimal place (exp)
while (n / 10 != 0)
{
exp = exp * 10;
n = n / 10;
}
n = x;
while (exp > 0)
{
// Extract each digit and print it
digit = n / exp;
_putchar(digit + '0');
n = n - (digit * exp);
exp = exp / 10;
i++;
}
}
// Print the last digit
_putchar(last + '0');
return (i);
}
