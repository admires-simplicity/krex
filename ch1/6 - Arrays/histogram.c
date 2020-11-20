#include <stdio.h>

# define IN	1
# define OUT	0
# define MAX_LEN	10

main()
{
	int c, n = 0, state = OUT;
	int occurences[MAX_LEN];

	for (int i = 0; i < MAX_LEN; ++i) occurences[i] = 0; //initialize null array

	while ((c = getchar()) != EOF) {
		
		if (!(c == ' ' || c == '\n' || c == '\t')) { //if not in word
			state = IN;
			++n;
		}
		else if (state = IN) { //just out of word
			state = OUT;
			++occurences[n-1];
			n = 0;
		}
	}
	if (state = IN) ++occurences[n-1];

	printf("\nHistogram:\n");
	for (int i = 0; i < MAX_LEN; ++i) {
		printf("%2d:", i+1);
		for (int j = 0; j < occurences[i]; ++j) printf("*");
		printf("\n");	
	}
}
