#include <stdio.h>
#define	MAXLINE	1000	/* MAX INPUT LINE SIZE, including \0 null char */

int getline(char line[], int maxline);
int remove_trail(char s[]);

/* remove_trail trailing blanks and tabs, and delete blank lines */
main()
{
	char line[MAXLINE];

	while (getline(line, MAXLINE) > 0)
		if (remove_trail(line) > 0)
			printf("%s", line);
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
int remove_trail (char s[])
{
	int i;

	i = 0;
	while (s[i] != ('\n'))	/* find newline character */
		++i;
	--i;			/* back off from '\n' */
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if (i >= 0) {		/* is it a nonblank line? */
		++i;
		s[i] = '\n';	/* put newline character back */
		++i;
		s[i] = '\0';	/* terminate the string */
	}
	return i;
}
