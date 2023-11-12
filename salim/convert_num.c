#include "main.h"
/**
 * hprint - print hex number lowercase
 * @ap: argument pointer
 * @params: params struct
 * Return: bytes printed
*/
int hprint(va_list ap, params_t *params)
{
    unsigned long l;
    int x = 0;
    char *ch;

    if (params->l_mod)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_mod)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned int);
    ch = conv(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    if (params->hflag && l)
    {
        *--ch = 'x';
        *--ch = '0';
    }
    params->unsign = 1;
    return (x += print_num(ch, params));
}
/**
 * Hprint - print hex number upcase
 * @ap: argument pointer
 * @params: params struct
 * Return: bytes printed
*/
int Hprint(va_list ap, params_t *params)
{
    unsigned long l;
    int x = 0;
    char *ch;

    if (params->l_mod)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_mod)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned int);
    ch = conv(l, 16, CONVERT_UNSIGNED, params);
    if (params->hflag && l)
    {
        *--ch = 'X';
        *--ch = '0';
    }
    params->unsign = 1;
    return (x += print_num(ch, params));
}
/**
 * bprint - prints binary
 * @ap: arg pointer
 * @params: params struct
 * Return: bytes printed
*/
int bprint(va_list ap, params_t *params)
{
    unsigned int u = va_arg(ap, unsigned int);
    char *ch = conv(u, 2, CONVERT_UNSIGNED, params);
    
    if (params->hflag && u)
        *--ch = '0';
    params->unsign = 1;
    return (u += print_num(ch, params));
}
/**
 * oprint - print octal
 * @ap: argument pointer
 * @params: params struct
 * Return: bytes printed
*/
int oprint(va_list ap, params_t *params)
{
    unsigned long l;
    char *ch;
    int x = 0;
    if (params->l_mod)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_mod)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned int);
    ch = conv(l, 8, CONVERT_UNSIGNED, params);

    if (params->hflag && l)
        *--ch = '0';
    params->unsign = 1;
    return (x +=print_num(ch, params));
}
