#include <stdio.h>
#define	MAXLINE	1000	/* MAX INPUT LINE SIZE, including \0 null char */

int getline(char line[], int maxline);
void remove_blanks(char line[]);

/* print longest input line */
main()
{
	int len;
	char line[MAXLINE];	/* current input line, with longest line junk bits at end */

	while ((len = getline(line, MAXLINE)) > 0) {
		remove_blanks(line);
		printf("%s", line);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
		if (i < lim-2)
			s[i] = c;
	s[lim-2] = '\n';
	s[lim] = '\0';
	return i;
}

/* remove trailing blanks and tabs, and entirely blank lines. */
void remove_blanks(char s[])
{
	int i;


}
