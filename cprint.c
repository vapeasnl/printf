#include "main.h"
/**
 * cprint - function that prints a character
 * @arg: the variadic arg from the printf function
 * Return: amount of characters printed (one).
**/
int cprint(va_list arg)
{
	char c = (char) va_arg(arg, int);

	_putchar(c);

	return (1);
}
