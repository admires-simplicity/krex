#include <stdio.h>
#define	MAXLINE	1000	/* MAX INPUT LINE SIZE, including \0 null char */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;		/* current line length */
	int max;		/* max length seen so far */
	char line[MAXLINE];	/* current input line, with longest line junk bits at end */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) /* while line has length, e.g. read something more than only EOF */
		if (len > max) {
			max = len;
			copy(longest, line);
					
		}
	if (max > 0)	/* there was a line */
		printf("\n\nLongest line is:\n%s\nLength: %d\n", longest, max);
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
	s[j] = '\0';
			
	printf("\tLine is:\n\t%s\tLength: %d\n", s, i);
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
