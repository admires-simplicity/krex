#include <stdio.h>
#define	MAXLINE	1000	/* MAX INPUT LINE SIZE, including \0 null char */
#define TABW	8	/* TAB WIDTH */

int getline(char line[], int maxline);
void detab(char s[]);

/* print longest input line */
main()
{
	int len;
	char line[MAXLINE];	/* current input line, with longest line junk bits at end */

	while ((len = getline(line, MAXLINE)) > 0) {
		detab(line);
		printf("%s", line);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void detab(char s[])
{
	int i = 0, j = 0, c;

	while (c != '\0') {
		


		if (j == 7) j = 0;
		else ++j;
		++i;
	}	
}
