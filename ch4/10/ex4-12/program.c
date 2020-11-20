#include <stdio.h>
#include <math.h>	//for the abs() function

void ritoa(int n, char []);

int main(void)
{
	char s[100];

	int x;

	x = 12345;
	ritoa(x, s);
	printf("int is: \"%d\"\n", x);
	printf("str is: \"%s\"\n\n", s);

	x = -679423345;
	ritoa(x, s);
	printf("int is: \"%d\"\n", x);
	printf("str is: \"%s\"\n\n", s);

	x = 51;
	ritoa(x, s);
	printf("int is: \"%d\"\n", x);
	printf("str is: \"%s\"\n\n", s);
}

void ritoa(int n, char s[])
{
	static int i;

	if (n / 10)
		ritoa(n / 10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10) //if n / 10 is not 0
		printd(n / 10);
	putchar(n % 10 + '0');
}
