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
	int i;

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	if (max > 0)	/* there was a line */
		printf("Longest line length is %d\n%s\n", max, longest);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
		if (i < lim - 2)
			s[i] = c;
	s[lim-1] = '\n';
	s[lim] = '\0'
	printf("This line is %d chars long.\n", i);
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
