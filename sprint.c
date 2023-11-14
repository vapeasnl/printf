#include "main.h"

/**
 * sprint - function that prints a string
 * @arg: the variadic arg from the printf function
 * Return: amount of characters printed
**/
int sprint(va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
