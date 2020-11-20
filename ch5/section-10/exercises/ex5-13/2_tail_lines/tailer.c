//Print only the last n lines of input
//Default n = 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allocator.h"

#define DEF_INPUT 10	//default number of input lines to print
#define MAXLINES 5000	//max # of input lines
#define MAXLEN 1000 	//max length of any input line

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int my_getline(char *, int);

char *lineptr[MAXLINES]; //pointer array. MAXLINES pointers, which each point to the first char of a string...
// i need a vangard pointer, which checks that there is still n chars left to input?

void readarg(int argc, char *argv[], int* to_print)
{
	int c, x;

	while (--argc > 0 && (*++argv)[0] == '-')	//in argv (pointer array), index 0 [first char] of next pointer in pointer array (derefd)
		while (c = *++argv[0])	//argv[0]: which pointer arv points to. ++argv[0]. index pointer argv pnts to (nxt chr in ptr). * deref.
			switch(c) {
				case 'n':
					x = atoi(*++argv);
					if (x >= 0)
						*to_print = x;
					else {
						printf("Error: can't delete a negative number of lines. Defaulted to 0.\n");
						*to_print = 0;
					}
					--argv;
					break;
			}
}


/*print last n input lines*/
int main (int argc, char *argv[])
{
	int to_print = DEF_INPUT;
	int lines;
	char **p;

	readarg(argc, argv, &to_print);

	if ((lines = readlines(lineptr, MAXLINES)) >= 0) {
		//to print only last to_print lines of lineptr,
		//index lineptr, lines - to_print times, right?
		p = &lineptr[lines - to_print];
		printf("Yo, here's yo lines, yo:\n");
		if (lines < to_print)
			writelines(lineptr, lines);
		else
			writelines(p, to_print);
	} else {
		printf("Error: Input byte limit is 10000... I think, lol.");
		return 1;
	}

	printf("\nla fin du programme\n");
	return 0;
}

char *alloc(int);

/*readlines: read input lines*/
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /*delete newline*/
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/*writelines: write output lines
 * V2 */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)			/*while there are lines*/
		printf("%s\n", *lineptr++);	/*ptr to first char of string, until \0, then index to next first char*/
}

/*my_getline: read a line into s, return length*/
int my_getline(char s[], int lim)
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
