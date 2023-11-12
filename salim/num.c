#include "main.h"
/**
 * conv -convfct
 * @num: number
 * @base: base
 * @flags: flags
 * @params: params struct
*/
char *conv(long int num , int base, int flags, params_t *params)
{
    static char *arr;
    static char buff[50];
    char sign = 0;
    char *ptr;
    unsigned long n = num;
    (void)params;

    if (!(flags & CONVERT_UNSIGNED) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buff[49];
    *ptr = '\0';
    do
    {
        *--ptr =arr[n % base];
        n /= base;
    } while (n != 0);
    if (sign)
        *--ptr = sign;
    return (ptr);
}
/**
 * uprint - print unsigned integer
 * @ap: argument pointer
 * @params: params struct
 * Return: bytes printed
*/
int uprint(va_list ap, params_t *params)
{
    unsigned long l;
    if (params->l_mod)
    l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->h_mod)
    l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l =(unsigned int)va_arg(ap, unsigned int);
    params->unsign = 1;
    return (print_num(conv(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * aprint - print adresse
 * @ap: argument pointr
 * @params: parameters struct
 * Return: byte printed
*/
int aprint(va_list ap, params_t *params)
{
    unsigned long int u = va_arg(ap, unsigned long int);
    char *ch;

    if (!u)
        return (_puts("(nil)"));
    ch = conv(u, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    *--ch = 'x';
    *--ch = '0';
    return (print_num(ch, params));
}
