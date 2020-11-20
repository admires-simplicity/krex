#include <stdio.h>

#define	MAXLINE	100
#define	YES	1
#define	NO	0

int htoi(char hexadecimal_string[]);
int get_line(char string[], int string_limit);
int is_hex_digit(char digit);

int main()
{
	char s[MAXLINE];
	int digits;	//n of digits in hex number
	int value;	//value of hex number

	while ((digits = get_line(s, MAXLINE)-2) > 0) {
		//printf("%s", s);
		printf("%d\n", digits);

		printf("HEX: %s", s);
		value = htoi(s);
		printf("DEC: %d\n", value);
	}

	return 0;
}

int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;
	if (s[i] == '0') {	/* skip optional 0x or 0X */
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	n = 0;	/*integer value to be returned*/
	inhex = YES;	/*assume valid hex digit*/
	for (; inhex == YES; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else
			inhex = NO;	/*not a valid hex digit*/
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

int is_hex_digit(char d)
{
	if (d >= '0' && d <= '9' || d >= 'A' && d <= 'Z' || d >= 'a' && d <= 'z')
		return 1;
	else
		return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	s[i] = '\n';
	s[++i] = '\0';
	//printf("This line is %d chars long.\n", i);
	return --i;
}
