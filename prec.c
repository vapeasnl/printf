#include "main.h"
/**
 * prec - search for match and execute for the associate function
 * @next: the character to match
 * @position: the position of next
 * Return: function where it matches and if there is no match
**/
int (*prec(const char *next, int position))(va_list)
{
	int i;
	spec_t opt[] = {
		{"s", sprint},
		{"c", cprint},
		{"d", iprint},
		{"i", iprint},
		{"b", bprint},
		{"x", xprint},
		{"X", xprint_extra},
		{"o", oprint},
		{"u", uprint},
		{NULL, NULL}
	};

	for (i = 0; opt[i].m != NULL; i++)
		if (opt[i].m[0] == next[position])
			return (opt[i].func);
	return (NULL);
}
