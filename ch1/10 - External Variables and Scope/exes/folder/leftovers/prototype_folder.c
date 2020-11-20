#include <stdio.h>

#define	TABW	8
#define	MAXLINE	80

/* Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column. */

/* 1. \n after the last nonblank char before the n-th column -> after last word before cutoff point
 * 2. Handle very long lines
 * 3. Handle no blanks / tabs before cutoff */

main()
{
	int c, i = 0, j = 0, pos = 1;

	while ((c = getchar()) != EOF) {
		if (pos > 80) {
			putchar('\n');
			putchar(c);
	       		pos = 2;
		} else {
			putchar(c);
			++pos;
		}
	}
}




