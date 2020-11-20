#include <stdio.h>

#define IN	1 //in word
#define OUT	0 //not

main()
{
	int state = OUT;
	int c;
	
	while((c = getchar()) != EOF) {
		if (!(c == ' ' || c == '\t' || c == '\n')) {
			putchar(c);
			state = IN; //good or bad practice ???
		}
		else if (state == IN) {
			state = OUT;
			putchar('\n');
		}

	}

}
