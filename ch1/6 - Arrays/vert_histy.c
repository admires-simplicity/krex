#include <stdio.h>

# define IN	1
# define OUT	0
# define MAXHIST	15
# define MAXWORD	11 //max len I want, + 1 for zero

main()
{
	int c, i, n = 0, ovflow = 0, maxvalue = 0, state = OUT;
	int occs[MAXWORD];		//occurences of word len
	int o[MAXWORD];

	for (i = 0; i < MAXWORD; ++i) occs[i] = 0; //init null array
	for (i = 0; i < MAXWORD; ++i) o[i] = 0; //init null array

	//count occurences of each word length
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (n > 0) 
				if (n < MAXWORD) ++occs[n];
				else ++ovflow;	
			n = 0;
		} else if (state == OUT) {
			state = IN;
			n = 1;
		} else ++n;
	}
	if (state == IN) ++occs[n];

	printf("\nHistogram:\n");

	for (i = 0; i < MAXWORD; ++i) if (occs[i] > maxvalue) maxvalue = occs[i];

	//CONVERT OCCS TO SCALED OCCS, SUCH THAT OCCS CAN BE USED FOR EACH ROW OF THE HISTY
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i) //get longest actual word (not ovflow)
		if (occs[i] > maxvalue) maxvalue = occs[i];
	for (i = 1; i < MAXWORD; ++i)  
		if (occs[i] > 0)  
			if ((o[i] = occs[i] * MAXHIST / maxvalue) <= 0) //assign, and errorcatch if less than 1
				o[i] = 1; 
	//CONVERT SCALED OCCS TO INVERSE SCALED OCCS, SUCH THAT HISTY CAN BE PRINTED
	for (i = 1; i < MAXWORD; ++i) o[i] = MAXHIST - o[i];
	
	//PRINT HISTY
	for (i = 0; i < MAXHIST; ++i) {
		for (int j = 1; j < MAXWORD; ++j) {
			if (o[j] > 0) {
				--o[j];
				putchar(' ');
			} else putchar('*');
		}
		putchar('\n');
	}

	printf("12345678901234567890\n00000000011111111112\n");
	for (i = 1; i < MAXWORD; ++i)
		printf("%5d - %5d\n", i, occs[i]);
	printf("ovflow = %d", ovflow);

	
	//kinda poorly written I think, but absolutely 0 bugs omega programming
}
