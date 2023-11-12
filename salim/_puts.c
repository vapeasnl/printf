#include "main.h"

/**
 * _puts - prints string with new line
 * @str: the string to print
 * Return: void
*/
int _puts(char *str)
{
    char *ch = str;
    while (*str)
    _putchar(*str++);
    return (str - ch);
}
/**
* _putchar - a function to writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and error is set appropriately.
*/
int _putchar(int c)
{
return (write(1, &c, 1));
}
