#include <stdio.h>

#define MAXHIST	15	/* max length of histogram */
#define MAXWORD	11	/* max length of word */
#define IN	1	/* inside word */
#define OUT	0	/* outside word */

//print horizontal histogram
main()
{
	int c, i, nc, state;
	int len;		//length of each bar
	int maxvalue;		//max value for wl[]
	int ovflow;		//number of overflow words
	int wl[MAXWORD];	//word length counters

	state = OUT;
	nc = 0;			//number of chars in a word
	ovflow = 0;		//number of words >= MAXWORD
	for (i = 0; i < MAXWORD; ++i) wl[i] = 0; //initialize null
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD) ++wl[nc];
				else ++ovflow;
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1; //beginning of a new word
		} else ++nc; //inside a word
	}
	printf("\nHistogram:\n");

	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i) //get longest actual word (not ovflow)
		if (wl[i] > maxvalue) maxvalue = wl[i];
	for (i = 1; i < MAXWORD; ++i) { //for each possible word length
		printf("%5d - %5d : ", i, wl[i]);
		if (wl[i] > 0) { //if there are words of this length
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0) //calculate len as how many times maxvalue can fit in MAXHIST times how many this occurs (necessarily less than or equal to MAXHIST)
				len = 1; //if len is purely fractional, floored (or negative, but I can't figure out why it'd be negative)
		} else len = 0;
		while (len > 0) {
			putchar ('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
