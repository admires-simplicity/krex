#include <stdio.h>

main ()
{
	int c;

	while ((c = getchar()) != EOF)
		printf("%c", c);
	c = getchar();		/* The test was to see if these lines throw an error, and they don't! */
	printf("%c", c);
	c = getchar();
	printf("%c", c);
	c = getchar();
	printf("%c", c); 
	if ((c = getchar()) == EOF) printf("yes lole"); /* prints yes lole */
}
