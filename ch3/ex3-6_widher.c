#include <stdio.h>
#include "helpers.h"

void itoa(int n, char s[]);
void itoa_p(int n, char s[], int p);

int main(void)
{
	char s[LENGTH];
	int n, p;

//	printf("n = ");
//	get_line(s, LENGTH);
//	n = atoi(s);
//
//	printf("pad = ");
//	get_line(s, LENGTH);
//	p = atoi(s);
//
//	itoa_p(n, s, p);
//	printf("|%s|\n", s);

	itoa_p(500, s, 3);
	printf("|%s|\n", s);
	itoa_p(-10, s, 5);
	printf("|%s|\n", s);
	itoa_p(4000, s, 2);
	printf("|%s|\n", s);
	itoa_p(3, s, 5);
	printf("|%s|\n", s);
}

/*itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void itoa_p(int n, char s[], int padding) {
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	while (i < padding)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

