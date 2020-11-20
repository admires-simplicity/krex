#include <stdio.h>

main()
{
	int x = 4;
	x &= (x-1);
	printf("%d\n", x);
}
