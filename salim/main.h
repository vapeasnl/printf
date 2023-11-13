#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h> 
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2
/**
 * struct params - marameters struct
 * @unsign: flag if unsigned value
 * @pflag: on if plus flag specified
 * @sflag: on if space specified
 * @hflag: oon if hashtag specified
 * @zflag: on _zero__
 * @mflag: on__minus_
 * @width: field with
 * @precision: _____
 * @h_mod: _______
 * @l_mod: ______
 */
typedef struct params
{
    unsigned int unsign : 1;
    unsigned int pflag : 1;
    unsigned int sflag : 1;
    unsigned int hflag : 1;
    unsigned int zflag : 1;
    unsigned int mflag : 1;

    unsigned int width;
    unsigned int precision;

    unsigned int h_mod : 1;
    unsigned int l_mod : 1;
} params_t;
/**
 * struct spec - struct token
 * @spec: format token
 * @func: the function associated
 */
typedef struct spec
{
    char *spec;
    int (*func)(va_list, params_t *);
} spec_t; 
int _puts(char *str);
int _putchar(int c);
int cprint(va_list ap, params_t *params);
int iprint(va_list ap, params_t *params);
int sprint(va_list ap, params_t *params);
int pprint(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);
char *conv(long int num , int base, int flags, params_t *params);
int uprint(va_list ap, params_t *params);
int aprint(va_list ap, params_t *params);
int (*getspec(char *s))(va_list ap, params_t *params);
int getprintfunc(char *s, va_list ap, params_t *params);
int getflag(char *s, params_t *params);
int getmod(char *s, params_t *params);
char *getwidth(char *s, params_t *params, va_list ap);
int hprint(va_list ap, params_t *params);
int Hprint(va_list ap, params_t *params);
int bprint(va_list ap, params_t *params);
int oprint(va_list ap, params_t *params);
int printcount(char *deb, char *fin,char *except);
int revprint(va_list ap, params_t *params);
int rotprint(va_list ap, params_t *params);
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, params_t *params);
int print_numright(char *str, params_t *params);
int print_numleft(char *str, params_t *params);
void init_params(params_t *params);
char *getprec(char*s, params_t *params, va_list ap);
int _printf(const char *format, ...);

#endif




