#include "main.h"
/**
 * _printf - printf
 * @format: --
 * Return: --
 */
int _printf(const char * const format, ...)
{
	int cnt = 0, i;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			cnt++;
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			cnt++;
			i++;
		}
		else if (format[i + 1] == 's')
		{
			cnt += _puts(va_arg(args, char *));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			cnt++;
			i++;
		}
		else
		{
			_putchar(format[i]);
			cnt++;
		}
	}
	va_end(args);
	return (cnt);
}
