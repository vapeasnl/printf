#include "main.h"
/**
 * _putchar - writes the character c
 * @c: The character to print
 * Return: On success 1
 * On error, return (-1), and error is set appropriately.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
