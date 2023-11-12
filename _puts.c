#include "main.h"
/**
* _puts --
* @str: --
* Return: --
*/
int _puts(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	}
	return (i);
}
