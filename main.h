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
int print_c(va_list val); /*print character*/
int print_s(va_list val); /*print string*/
int print_37ASCII(void); /*print the character %*/
int print_i(va_list args); /*print integer*/
int print_d(va_list args); /*print decimal*/
int print_b(va_list val); /*print binary*/
int print_u(va_list args); /*print unsigned integer*/
int print_o(va_list val); /*print integer as an octal*/
int print_X(va_list val); /*print integer as an hexadecimal uppcaser*/
int print_x(va_list val); /*print integer as an hexadecimal lowecaser*/
int print_x_extra(unsigned long int num); 
int print_X_extra(unsigned int num);
int print_S(va_list val);/*print a wide character string*/
int print_p(va_list val); /*print a pointer*/
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int print_revs(va_list args);
int print_R(va_list args); /*print rot13*/
int _strlen(char *s);
int r_string(char *s); /*reverse string*/
#endif
