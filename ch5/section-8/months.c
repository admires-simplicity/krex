#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n)
{
	static char *name[] = {			//where is this stored???
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void)
{	
	int i;

	for (i = 0; i < 14; ++i)
		printf("The %2d-th month is %s\n", i, month_name(i)); //TO USE THE STRING THE FUNCTION RETURNS, THIS STATEMENT DOESN'T USE THE ASTERISK
}
