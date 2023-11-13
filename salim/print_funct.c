#include "main.h"
/**
 * cprint - print char
 * @ap: arg point
 * @params: params struct
 * Return: number char printed
*/
int cprint(va_list ap, params_t *params)
{
    char pchar = ' ';
    unsigned int p = 1, count = 0, str = va_arg(ap, int);

    if (params->mflag)
    {
        count += _putchar(str);
    }
        while (p++ < params->width)
            count += _putchar(pchar);
        if (!params->mflag)
            count += _putchar(str);
        return (count);
}
/**
 * iprint - print integer
 * @ap: arg point
 * @params: params struct
 * Return: number char printed
*/
int iprint(va_list ap, params_t *params)
{
    long l;
    if (params->l_mod)
        l = va_arg(ap, long);
    else if (params->h_mod)
        l = (short int)va_arg(ap, int);
    else
        l = (int)va_arg(ap, int);
    return (print_num(conv(l, 10, 0, params),params));
}
/**
 * sprint - print string
 * @ap: arg point
 * @params: params struct
 * Return: number char printed
*/
int sprint(va_list ap, params_t *params)
{
    char *ch = va_arg(ap, char *), pchar = ' ';
    unsigned int p = 0, count = 0, a = 0, b;

    (void)params;
    switch ((int)(!ch))
    {
        case 1:
            ch = NULL_STRING;
            break;
    }
    b = p = _strlen(ch);
    if (params->precision < p)
        b = p = params->precision;
    
    if (params->mflag)
    {
        if (params->precision != UINT_MAX)
            for (a = 0; a < p; a++)
                count += _putchar(*ch++);
        else
            count += _puts(ch);
    }
    while (b++ < params->width)
        count += _putchar(pchar);
    if (!params->mflag)
    {
        if (params->precision != UINT_MAX)
            for (a = 0; a < p; a++)
                count += _putchar(*ch++);
        else
            count += _puts(ch);
    }
    return (count);
}
/**
 * pprint - print percent %
 * @ap: arg point
 * @params: params struct
 * Return: number char printed
*/
int pprint(va_list ap, params_t *params)
{
    (void)ap;
    (void)params;
    return (_putchar('%'));
}
/**
 * Sprint - print percent %
 * @ap: arg point
 * @params: params struct
 * Return: number char printed
*/
int Sprint(va_list ap, params_t *params)
{
    char *ch = va_arg(ap, char *);
    char *hexa;
    int count = 0;

    if ((int)(!ch))
        return (_puts(NULL_STRING));
    for (; *ch; ch++)
    {
        if ((*ch > 0 && *ch < 32) || *ch >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            hexa = conv(*ch, 16, 0, params);
            if (!hexa[1])
                count += _putchar('0');
            count += _puts(hexa);
        }
        else
        {
            count += _putchar(*ch);
        }
    }
    return (count);
}
