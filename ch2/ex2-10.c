#include <stdio.h>

#define	array_len	10

int lower(int c);
int lower_conditional_exp(int c);

main()
{
	int i;
	char str[array_len] = "Oh, YEAH\n";

	printf("%s", str);

	for (i = 0; i < array_len; ++i)
		str[i] = lower_conditional_exp(str[i]);

	printf("%s", str);
}


int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int lower_conditional_exp(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
}
