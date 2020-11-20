#include <stdio.h>

#define	MAXLINE	1000
#define	TRUE	1
#define	FALSE	0

int get_line(char string[], int string_limit);
void squeeze_string(char original[], char exclude[]); 
int len(char s[]);

int main()
{
	char s1[MAXLINE];
	char s2[MAXLINE];

	printf("Original: ");
	get_line(s1, MAXLINE);
	printf("Exclude : ");
	get_line(s2, MAXLINE);

	squeeze_string(s1, s2);

	printf("%s", s1);

	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	s[i] = '\n';
	s[++i] = '\0';
	return --i;
}

void squeeze_string(char s1[], char s2[])
{
	int i, j, k = 0;
	int char_found = FALSE;

	for (i = 0; s1[i] != '\0'; ++i) {		/*for each char in s1*/
		for (j = 0; s2[j] != '\0'; ++j) {	/*for each char in s2*/
			if (s1[i] == s2[j]) char_found = TRUE; /*set found to true if char is found*/
		}
		if (char_found == FALSE) {			/*if char s1[i] has been found in s2*/
			s1[k++] = s1[i];			/*squeeze it out*/
		} else
			char_found = FALSE;	/* reset char_found */
	}
	s1[k] = '\0';
}

int len(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	
	return i;
}
