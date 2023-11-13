#include "main.h"

int print_string(va_list args)
{
    char *str;
    int len;

    str = va_arg(args, char *);
    if (str == NULL)
    {
        str = "(null)";
        len = 0;
        while (str[len])
        {
            _putchar(str[len]);
            len++;
        }
        return (len);
    }
    else
    {
        len = 0;
        while (str[len])
        {
            _putchar(str[len]);
            len++;
        }
        return (len);
    }
}

