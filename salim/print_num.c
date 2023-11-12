#include "main.h"
/**
* _isdigit - check numbers beetwen 0 - 9
* @c: char to be checked
*
* Return: 0 or 1
*/
int _isdigit(int c)
{
if (c >= '0' && c <= '9')
return (1);
else
return (0);
}
/**
* _strlen - returns the length
* @s: string
* Return: length
*/
int _strlen(char *s)
{
int i = 0;
while (*s != '\0')
{
i++;
s++;
}
return (i);
}
/**
 * print_numright - print num
 * @str: the base number as a string
 * @params: the paramas struct
 * Return: char printed
*/
int print_numright(char *str, params_t *params)
{
    unsigned int u = 0, x1, x2, i = _strlen(str);
    char pchar = ' ';

    if (params->zflag && !params->mflag)
        pchar = '0';
    x1 = x2 = (!params->unsign && *str == '-');
    if (x1 && i < params->width && pchar == '0' && !params->mflag)
    str++;
    else
        x1 = 0;
    if ((params->pflag && !x2) || (!params->pflag && params->sflag && !x2))
        i++;
    if (x1 && pchar == '0')
        u += _putchar('-');
    if (params->pflag && !x2 && pchar == '0' && !params->unsign)
        u += _putchar('+');
    else if (!params->pflag && params->sflag && !x2 && !params->unsign && params->zflag)
        u += _putchar(' ');
    while (i++ < params->width)
        u += _putchar(pchar);
    if (x1 && pchar == ' ')
        u += _putchar('-');
    if (params->pflag && !x2 && pchar == ' ' && !params->unsign)
        u += _putchar('+');
    else if (!params->pflag && params->sflag && !x2 && !params->unsign && !params->zflag)
        u += _putchar(' ');
    u += _puts(str);
    return (u);
}
/**
 * print_numleft - prints number with option
 * @str: base
 * @params: params struct
 * Return: char printed
*/
int print_numleft(char *str, params_t *params)
{
    unsigned int u = 0, x1, x2, i = _strlen(str);
    char pchar = ' ';
    if (params->zflag && !params->mflag)
        pchar = '0';
    x1 = x2 = (!params->unsign && *str == '-');
    if (x1 && i < params->width && pchar == '0' && !params->mflag)
    str++;
    else
        x1 = 0;
    
    if (params->pflag && !x2 && !params->unsign)
        u += _putchar('+'), i++;
    else if (params->sflag && !x2 && !params->unsign)
        u += _putchar(' '), i++;
    u += _puts(str);
    while (i++ < params->width)
    {
        u += _putchar(pchar);
    }
    return (u);
}
/**
 * print_num - print number
 * @str: the base
 * @params: the params struct
 * Return: chars printed
*/
int print_num(char *str, params_t *params)
{
    unsigned int u = _strlen(str);
    int x = (!params->unsign && *str == '-');
    if (!params->precision && *str == '0' && !str[1])
    str = "";
    if (x)
    {
        str++;
        u--;
    }
    if (params->precision != UINT_MAX)
        while (u++ < params->precision)
            *--str = '0';

    if (x)
        *--str = '-';

    if (!params->mflag)
        return (print_numright(str, params));
    else
        return (print_numleft(str, params));
}

