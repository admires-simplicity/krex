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
		/* printf("hello"); */
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

/* reverse string */
void reverse (char s[])
{
	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')	/* str end */
		++i;
	--i;			/* back off to disinclude '\0' */
	if (s[i] == '\n') --i;	/* "			" '\n' */
	j = 0;
	while (j < i) {
		temp = s[j];
		s[j] = s[i];	/* swap */
		s[i] = temp;
		--i;
		++j;
	}
}
