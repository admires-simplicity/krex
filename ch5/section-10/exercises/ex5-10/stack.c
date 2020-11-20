#include <stdio.h>
#include "calc.h"

#define MAXVAL 100 /*max depth of stack*/

static double val[MAXVAL];	/* THE STACK */
static double *p = val;		/* ptr to next free stack pos */

/*push: push f onto stack*/
void push(double f)
{
	//printf("stack index before push == %2d\n", p - val);

	if (p < val + MAXVAL)	//I think this is right, but it might be off by 1?
		*p++ = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/*pop: pop and return top value from stack*/
double pop(void)
{
	//printf("*p (ptr to next free position) - val (array origin) == %2d\n", p - val);
	//printf("pop index %2d\n", p - val);

	if (p - val > 0)
		return *--p;
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
