#include "main.h"
/**
 * printcount - print range
 * @deb: start
 * @fin: stopping
 * @except: except adress
 * Return: number byte printed
*/
int printcount(char *deb, char *fin,char *except)
{
    int count = 0;

    while (deb != fin && deb != except)
    {   
        count += _putchar(*deb);
        deb++;
    }
    return (count);
}
/**
 * revprint - print string reverse
 * @ap: argument pointer
 * @params: the parameteres strut
 * Return: number bytes printed
*/
int revprint(va_list ap, params_t *params)
{
    int lenght, count = 0;
    char *ch = va_arg(ap, char *);
    (void)params;

    if (ch)
    {
        for (lenght = 0; *ch; ch++)
            lenght++;
        ch--;
        for (; lenght > 0; lenght--, ch--)
        {
            count += _putchar(*ch);
        }
    }
    return (count); 
}
/**
 * rotprint - print string in rot 13
 * @ap: string
 * @params: the params struct
 * Return: number of byte
*/
int rotprint(va_list ap, params_t *params)
{
    int x, head;
    int sum = 0;
    char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM       nopqrstuvwxyzabcdefghijklm";
    char *a = va_arg(ap, char *);
    (void)params;

    x = 0;
    head = 0;
    while (a[x])
    {
        if ((a[x] >= 'A' && a[x] <= 'Z') || (a[x] >= 'a' && a[x] <= 'z'))
        {
            head = a[x] - 65;
            sum += _putchar(arr[head]);
        }
        else
            sum += _putchar(a[x]);
        x++;
        
    }
    return (sum);
}
