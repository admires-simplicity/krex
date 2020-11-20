//Print the last n lines of input...
//by default n is 10. n can be changed
//	-n x
//to change n to x

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allocator.h"

#define MAXLINES 5000	//max # of input lines
#define MAXLEN 1000 	//max length of any input line

int readinput(char *lineptr[], int maxlines);
void write_xtail(char *lineptr[], int total, int exclude);
int my_getline(char *, int);


char *lineptr[MAXLINES]; //pointer array. MAXLINES pointers, which each point to the first char of a string...
// i need a vangard pointer, which checks that there is still n chars left to input?

void readarg(int argc, char *argv[], int* tail_omit)
{
	int c, x;

	while (--argc > 0 && (*++argv)[0] == '-')	//in argv (pointer array), index 0 [first char] of next pointer in pointer array (derefd)
		while (c = *++argv[0])	//argv[0]: which pointer arv points to. ++argv[0]. index pointer argv pnts to (nxt chr in ptr). * deref.
			switch(c) {
				case 'n':
					x = atoi(*++argv);
					if (x >= 0)
						*tail_omit = x;
					else
						printf("Error: can't delete a negative number of chars. Defaulted to 10.\n");
					--argv;
					break;
			}
}


/*sort input lines*/
int main (int argc, char *argv[])
{
	int count = 0;
	int tail_omit = 10;

	readarg(argc, argv, &tail_omit);

	if ((count = readinput(lineptr, MAXLINES)) >= 0) {
		//printf("count = %4d\n", count);
		write_xtail(lineptr, count, tail_omit);
		//writelines(lineptr, 1);
	} else {
		printf("Error: Input byte limit is 10000... I think, lol.");
		return 1;
	}

	printf("\nla fin du programme\n");
	return 0;
}

char *alloc(int);

/*readlines: read input lines*/
int readinput(char *lineptr[], int maxlines)
{
	int len, nlines, count = 0;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			strcpy(p, line);
			count += strlen(p);
			lineptr[nlines++] = p;
		}
	return count;
}

void write_xtail(char *lineptr[], int total, int exclude)
{
	//lineptr is a pointer, which points to a pointer, which points to a char...
	
	char* p = *lineptr;
	//p now points to the first char of the first string...
	
	int i = exclude;

	//printf("\ntotal=%d, exclude=%d, so will print %d chars!\n", total, exclude, total-exclude);
	
	while (i < total)
		if (*p != '\0') {
			putchar(*p++);
			++i;
		}
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
