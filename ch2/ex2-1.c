/*pg 48, pg 267*/

#include <limits.h>
#include <float.h>
#include <stdio.h>

main()
{
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);

	printf("ULONG_MAX: %ul\n", ULONG_MAX);

	char c;
	for(int i = 0; i<=300; ++i) {
		++c;
		printf("%d, ", c);
	}
	printf("%d\n", c);
}
