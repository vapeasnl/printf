#include "main.h"
/**
 * _printf - printf
 * @format: --
 * Return: --
 */
int _printf(const char * const format, ...)
{
	unsigned int cnt = 0, i, s_cnt;

	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			continue;
		}
		if (format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;
			continue;
		}
		if (format[i + 1] == 's')
		{
			s_cnt = _puts(va_arg(args, char *));
			i++;
			cnt += (s_cnt - 1);
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			continue;
		}

		cnt++;
	}

	va_end(args);
	return (cnt);
}
