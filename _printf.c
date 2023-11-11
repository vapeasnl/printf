#include "main.h"
/**
 * _printf - printf
 * @format: --
 * Return: --
 */
int _printf(const char * const format, ...)
{
convert tab[] = {
{"%s", print_s}, {"%c", print_c},
{"%%", print_37ASCII},
{"%i", print_i}, {"%d", print_d}
};
va_list args;
int i = 0, j, len = 0;
va_start(args, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);
Here:
while (format[i] != '\0')
{
j = 5;
while (j >= 0)
{
if (tab[j].pch[0] == format[i] && tab[j].pch[1] == format[i + 1])
{
len += tab[j].function(args);
i = i + 2;
goto Here;
}
j--;
}
_putchar(format[i]);
len++;
i++;
}
va_end(args);
return (len);
}
