#include "main.h"

int print_char(va_list args)
{
    char character;

    character = va_arg(args, int);
    _putchar(character);
    return (1);
}

