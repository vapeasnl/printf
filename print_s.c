#include "main.h"
/**
* print_s - print a string.
* @val: value argument.
* Return: the length of the string.
*/
int print_s(va_list val)
{
char *str;
int x, lenght;
str = va_arg(val, char *);
if (str == NULL)
{
str = "(null)";
lenght = _strlen(str);
for (x = 0; x < lenght; x++)
_putchar(str[x]);
return (lenght);
}
else
{
lenght = _strlen(str);
for (x = 0; x < lenght; x++)
_putchar(str[x]);
return (lenght);
}
}
