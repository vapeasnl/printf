#include "main.h"
/**
 * _strlenc - finds length of a string but for constant characters
 * @s: string
 * Return: integer
 */
int _strlenc(const char *s)
{
int ch;
for (ch = 0; s[ch] != 0; ch++)
;
return (ch);
}
