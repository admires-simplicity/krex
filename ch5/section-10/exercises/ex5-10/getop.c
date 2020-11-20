#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/*getop: get next op[erator/erand]*/
int getop(char *s)
{
	int i, c, sign = 1;

	if (!isdigit(*s) && *s != '.' && *s != '-' && *s != '+')
			return *s;		//definetly not a number

	if (*s == '-' || *s == '+') {
		if (isdigit(*(s+1)) || (*(s+1) == '.' && isdigit(*(s+2)))) {
			if (*s == '-')
				sign = -1;
		}
		else
			return *s;		//*s is + or -
	}

	return NUMBER;		//doesn't error check for a lot of stuff but whutevva
}

//a second thought on returning number...
//atof returns 0 whenever there's an error, so if calc is fed bad input, it'll just read as 0... bad, but... not so bad....
