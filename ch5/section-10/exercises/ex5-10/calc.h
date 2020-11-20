/* Header for calculator functions */
#include <stdio.h>

#ifndef CALCH
#define CALCH

#define NUMBER '0'
#define NULL_TERMINATOR '\0'

void push(double);
double pop(void);
int getop(char *s);

#endif
