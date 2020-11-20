#include <stdio.h>

/*Copy input to output, replacing each string of spaces by one space*/
main()
{
	int c;

	while ((c = getchar()) != EOF) {		
		if (c == ' ') {				//if space
			while ((c = getchar()) == ' ')  //while next char is space
				;			//do nothing
			putchar(' ');			//put space
			putchar(c);			//put the char which is not space
		}
		else putchar(c);			//else put c
	}	
	
}
