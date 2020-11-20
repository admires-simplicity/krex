#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	static int lastc = 0;
	int i, c;

	if (lastc) {
		c = lastc;
		lastc = 0;
	} else {
		c = getch()
	}

	while ((s[0] = c) == ' ' || c == '\t')	//skip whitespace
			c = getch();
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	//Handle number:
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	return NUMBER;
}
