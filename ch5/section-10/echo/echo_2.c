#include <stdio.h>

//echo cli arguments, v2
main(int argc, char *argv[])
{
	while (--argc > 0)
		printf((argc > 1) ? "%s " : "%s", *++argv);
	printf("\n");
	return 0;
}
