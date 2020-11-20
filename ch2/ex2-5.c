#include <stdio.h>

#define	MAXLINE	1000
#define	TRUE	1
#define	FALSE	0

int get_line(char string[], int string_limit);
int any(char original[], char exclude[]); 
int len(char s[]);

int main()
{
	char s1[MAXLINE];
	char s2[MAXLINE];

	printf("Original     : ");
	get_line(s1, MAXLINE);
	printf("1st common in: ");
	get_line(s2, MAXLINE);

	printf("First common index is %d\n", any(s1, s2));

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

/*returns the lowest index in s1 which is equal to any char in s2*/
int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i) {		/*for each char in s1*/
		for (j = 0; s2[j] != '\0'; ++j) 	/*for each char in s2*/
			if (s1[i] == s2[j]) return i;	/*if equal, return i*/
	}
	return -1;
}

int len(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	
	return i;
}
