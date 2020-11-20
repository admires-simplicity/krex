#include <stdio.h>
#include <stdlib.h>	//for atof()

#include "calc.h"

int main(int argc, char *argv[])
{
	int type;
	double op;

	while (--argc > 0) {
		//printf("argc == %2d\n", argc);
		switch (type = getop(*++argv)) {
			case NUMBER:		
				//printf("num\n");
				push(atof(*argv));
				break;
			case '+':
				//printf("plu\n");
				push(pop() + pop());
				break;
			case '-':
				//printf("min\n");
				op = pop();
				push(pop() - op);
				break;
			case 'x':		//I had this operator as *, but bash was reading it as an "all in dir", rather than plain asterisk, so i had to change it.......
				//printf("mul\n");
				push(pop() * pop());
				break;
			case '/':
				//printf("div\n");
				op = pop();
				if (op != 0.0)
					push(pop() / op);
				else
					printf("ERROR: ZERO DIVISOR!\n");
				break;
		}
	}
	printf("%.8g\n", pop());
}
