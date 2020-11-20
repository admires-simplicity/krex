#include <stdio.h>

//get_line, pointer version....
int get_line(char *s, int lim)
{
	int c;
	char *t = s;

	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;	//the thing which s points to is equal to c, then incrememnt s
	if (c == '\n')
		*s++ = c;	//the thing which s points to is equal to c, then incrememnt s
	*s = '\0';
	return s - t;
}
