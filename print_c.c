#include "main.h"
/**
* print_c - print a character
* @val: value argument
* Return: integer
*/
int print_c(va_list val)
{
char ch;
ch = va_arg(val, int);
_putchar(ch);
return (1);
}
