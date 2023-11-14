#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <limits.h>
/**
 * struct spec - structure
 * @m: the spec to match after %
 * @func: the function to call
 */
typedef struct spec
{
	char *m;
	int (*func)(va_list);
}
spec_t;

int _putchar(char c);

int _printf(const char *format, ...);

int cprint(va_list arg);

int sprint(va_list arg);

int (*prec(const char *next, int position))(va_list);

int iprint(va_list args);

int bprint(va_list b);

int xprint(va_list args);

int xprint_extra(unsigned long int args);

int oprint(va_list args);

int uprint(va_list val);

#endif

