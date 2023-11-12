#include "main.h"
/**
* _strlen - the lenght of a string.
* @s: string
* Return: integer.
*/
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != 0; i++)
;
return (i);
}
