#include "main.h"

int _printf(const char *format, ...)
{
    conversion specifiers[] = {
        {"%s", print_string},
        {"%c", print_char},
        {"%%", print_percent},
    };

    va_list args;
    int i = 0, j, length = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        j = 2;
        while (--j >= 0)
        {
            if (specifiers[j].specifier[0] == format[i] && specifiers[j].specifier[1] == format[i + 1])
            {
                length += specifiers[j].printer(args);
                i = i + 2;
                goto Here;
            }
        }
        _putchar(format[i]);
        length++;
        i++;

    Here:
        continue;
    }
    va_end(args);
    return (length);
}

