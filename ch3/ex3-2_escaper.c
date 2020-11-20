#include <stdio.h>

#define	LEN	100

void escape(char s[], char t[]);
void incape(char s[], char t[]);
int get_line(char s[], int lim);

int main(void)
{
	char original[LEN], copy[LEN];
	int i;

	printf("%d\n", get_line(original, LEN));
	escape(original, copy);
	printf("%s\n", copy);
	
	// PLAINTEXT TO ESCAPE SEQ
//	printf("%d\n", get_line(original, LEN));
//	incape(original, copy);
//	printf("INCAPED STRING: %s\n", copy);
	
	
}

/* Copies string s to string c, while converting escape sequences to plain characters. Resultant string c is therefor longer than s. */
void escape(char s[], char t[])
{
	int i = 0; // s iterator
	int j = 0; // t iterator

	for ( ; j < LEN; ++i) { //I COULD RUN UNTIL \0 and append \\ 0 ...
		switch (s[i]) { // element of s
			case '\n': 
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\'':
				t[j++] = '\\';
				t[j++] = '\'';
				break;
			case '\"':
				t[j++] = '\\';
				t[j++] = '\"';
				break;
			case '\\':
				t[j++] = '\\';
				t[j++] = '\\';
				break;
			case '\0':
				t[j++] = '\\';
				t[j++] = '0';

			default:
			       t[j++] = s[i];
			       break;
		}
	}	

}

/* Copies string s to string c, while converting plain-character-escape-sequences to escape-sequences */
void incape(char s[], char t[])
{
	int i = 0; // s iterator
	int j = 0; // t iterator

	for ( ; i < LEN; ++j) {
		switch (s[i]) { //for s[i]
			case '\\': //if s[i] is a slash
				switch (s[++i]) { // check next char
					case 'n':
						t[j] = '\n';
						break;
					case 't':
						t[j] = '\t';
						break;
					case '\'':
						t[j] = '\'';
						break;
					case '\"':
						t[j] = '\"';
						break;
					case '\\':
						t[j] = '\\';
						break;
					case '\0':
						t[j] = '\0';
						break;
				}
				++i; //increment i
				break;

			default:
				t[j] = s[i];
				++i; //increment i
				break;
		}
	}
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
