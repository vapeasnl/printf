#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
* struct format - converter for printf
* @pch: a pointer type char for the specifier
* @function: function for the conversion specifier
*/
typedef struct format
{
char *pch;
int (*function)();
} convert;

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list val);
int print_s(va_list val);
int print_i(va_list args);
int print_d(va_list args);
int print_b(va_list val);
int print_u(va_list args);
int print_o(va_list val);
int print_X(va_list val);
int print_x(va_list val);
int print_x_extra(unsigned long int num);
int print_X_extra(unsigned int num);
int print_S(va_list val);
int print_p(va_list val);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int print_revs(va_list args);
int print_R(va_list args);
int r_string(char *s);
int print_37ASCII(void);

#endif
