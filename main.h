#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct format
{
    char *specifier;
    int (*printer)(va_list args);
} conversion;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif

