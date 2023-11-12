#include "main.h"
/**
 * getprec - get the precision
 * @s: string format
 * @params: the parameters struct
 * @ap: argment pointer
 * Return: new pointer
*/
char *getprec(char*s, params_t *params, va_list ap)
{
    int x = 0;
    if (*s != '.')
    return (s);
    s++;
    if (*s == '*')
    {
        x = va_arg(ap, int);
        s++;
    }
    else
    {
        while (_isdigit(*s))
        x = x * 10 + (*s++ - '0');
    }
    params->precision = x;
    return (s);
}
