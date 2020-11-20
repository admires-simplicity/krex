//sort, modiffied to illustrate pointers to functions

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /*max #lines to be sorted */

char *lineptr[MAXLINES]; /*pointers to text lines*/

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineprt[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char*);

/*sort input lines*/
int main (int argc, char *argv[])
{
	int nlines;	/* number of input lines read */
	int numeric = 0;	// 1 if numeric sort

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
			numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp)); //strcmp and numcmp are function adresses
		writelines(lineptr, nlines);			//since they are known functions, the & operator is unnecessary, just like array names
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 /*max length of any input line*/
int my_getline(char *, int);
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

/////*writelines: write output lines*/
////void writelines(char *lineptr[], int nlines)
////{
////	int i;
////
////	for (i = 0; i < nlines; i++)
////		printf("%s\n", lineptr[i]);
////}

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

/*q_sort: sort v[left]...v[right] into increasing order*/
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)	/*do nothing if array contains*/
		return;		/*fewer than two elements*/
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i<=right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last-1, comp);
	q_sort(v, last+1, right, comp);
}

#include <stdlib.h>
//numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atoi(s1);
	v2 = atoi(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/*swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
