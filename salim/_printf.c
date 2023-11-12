#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 * Return: number of bytes printed
*/
int _printf(const char *format, ...)
{
    int sum=0;
    va_list ap;
    char *p, *deb;
    params_t params = PARAMS_INIT;

    va_start(ap, format);

    if (!format || (format[0] == '%' && !format[1]))
    return (-1);
    if (format[0] == '%' && format[1] == ' ' && !format[2])
    return (-1);
    for (p = (char *)format; *p; p++)
    {
        init_params(&params);
        if (*p != '%')
        {
            sum += _putchar(*p);
            continue;
        }
        deb = p;
        p++;
        while (getflag(p, &params))
        {
            p++;
        }
        p = getwidth(p, &params, ap);
        p = getprec(p, &params, ap);
        if (getmod(p, &params))
        p++;
        if (!getspec(p))
        {
            sum += printcount(deb, p, params.l_mod || params.h_mod ? p -1 : 0);
        }
        else
        {
            sum += getprintfunc(p, ap, &params);
        }
    }
    _putchar(BUF_FLUSH);
    va_end(ap);
    return (sum);
}

