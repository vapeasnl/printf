#include "main.h"
/**
 * getmod - finds the mod func
 * @s: the format string
 * @params: params struct
 * Return: if modified was valid
*/
int getmod(char *s, params_t *params)
{
    int i = 0;
    switch (*s)
    {
    case 'h':
        i = params->h_mod = 1;
        break;
    case 'l':
        i = params->l_mod = 1;
    
        break;
    }
    return (i);
}
/**
 * getspec - finds the format
 * @s: the format string
 * Return: the num of bytes printed
*/
int (*getspec(char *s))(va_list ap, params_t *params)
{
    spec_t spec[] = { 
        {"c", cprint},
        {"d", iprint},
        {"i", iprint},
        {"s", sprint},
        {"%", pprint},
        {"b", bprint},
        {"o", oprint},
        {"u", uprint},
        {"X", Hprint},
        {"x", hprint},
        {"p", aprint},
        {"S", print_s},
        {"r", revprint},
        {"R", rotprint},
        {NULL, NULL}
    };
    int x = 0;
    
    while (spec[x].spec)
    {
        if (*s ==spec[x].spec[0])
        {
            return (spec[x].func);
        }
        x++;
    }
    return (NULL);
}
/**
 * getprintfunc - finds the format 
 * @s: the format string
 * @ap: argumen ponter
 * @params: the parameters struct
 * Return: the number of bytes printed
*/
int getprintfunc(char *s, va_list ap, params_t *params)
{
    int (*f)(va_list, params_t *) = getspec(s);

    if (f)
    return (f(ap, params));
    return (0);
}
/**
 * getflag - finds the flag func
 * @s: the format str
 * @params:the parameters struct
 * Return: if flag was valid
*/
int getflag(char *s, params_t *params)
{
    int i = 0;

    switch (*s)
    {
	    case '+':
        i = params->pflag = 1;
        break;
	    case ' ':
        i = params->sflag = 1;
        break;
	    case '0':
        i = params->zflag = 1;
        break;
	    case '-':
        i = params->mflag = 1;
        break;
    }
    return (i);
}
/**
 * getwidth - get the width
 * @s: string
 * @ap: argument
 * @params: parameter
 * Return: new pointer
*/
char *getwidth(char *s, params_t *params, va_list ap)
{
    int x = 0;
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
    params->width = x;
    return (s);
}
