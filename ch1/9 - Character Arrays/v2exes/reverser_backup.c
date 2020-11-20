#include <stdio.h>
#define	MAXLINE	1000	/* MAX INPUT LINE SIZE, including \0 null char */

int getline(char line[], int maxline);
void reverse(char s[]);

/* remove_trail trailing blanks and tabs, and delete blank lines */
main()
{
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
		if (j < lim-1) {
			s[i] = c;
			++j;
		}
		/* if (i > 1000000000) break; */
	}
	if (c == '\n') { /* takes \n from the end of string, because for loop stops when hits \n */
		s[j] = c;
		++i;
		++j;
	}
	s[j] = '\0';
			
	/* if (i > 0) printf("\tLine is:\n\t%s\tLength: %d\n", s, i); */
	return i;
}

/*remove_trail trailing blanks and tabs from character string s */
void reverse (char s[])
{
	int len = 0, i = 0, j, c;

	while (len == 0) {
		if (s[i] == '\n') len = i;
		else ++i;	
	}	
	j = i;

	for (i; i > 0; --i) {
		c = s[i];
		s[i] = s[i-j];
		s[i-j] = c;	
	}

	printf("%d\n", len);
	
}
