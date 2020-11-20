/*can I not just put an include stdio.h here, and then all the files which include this include it also?*/
#include <stdio.h>

#define NUMBER	'0'
void push (double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
