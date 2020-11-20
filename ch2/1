#include <stdio.h>

#define	MAXLINE	100
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
	int error = 0, i, value = 0;

	if (s[1] == 'x' || s[i] == 'X') {
		if (s[0] == '0') {
			//CALCULATE HEX LOLE
			for (i = 2; s[i] != '\n'; ++i) {
				if (!is_hex_digit(s[i])) 
					++error;	
				else 
					value = value * 16 + (s[i] - '0');
			}

		} else
			++error;
	} else
		++ error;

	if (error != 0) {
		printf("%d ERRORS! FUCK YOU PAL!", error);
	}
	return value;
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
