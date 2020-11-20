#include <string.h>

#define	LENGTH	1000

int get_line(char s[], int lim);
void reverse(char s[]);
int atoi(char s[]);
int trim(char s[]);

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	s[i] = '\n';
	s[++i] = '\0';
	return --i;
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int atoi(char s[]) {
	int n = 0;
	int i = 0;

	while (s[i] != '\n') { //because my function get_line always ends strings with \n \0
		n *= 10;
		n += (s[i++] - '0');
	}

	return n;
}

/*trim: remove trailing blanks, tabs, newlines*/
int trim(char s[])
{
	int n;

	for (n = strlen(s)-1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	s[n+1] = '\0';
	return n;
}
