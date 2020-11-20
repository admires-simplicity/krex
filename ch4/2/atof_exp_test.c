#include <stdio.h>
#include "atof.h"

main()
{
//	char yeehaw[9] = "123.45E6";
	char yeehaw[9] = "420.69";
	double d;

	d = atof(yeehaw);

	printf("%f\n", d);
}
