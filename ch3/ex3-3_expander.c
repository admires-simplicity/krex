#include <stdio.h>
#include "helpers.h"

void expand(char s1[], char s2[]);
void ans_expand(char s1[], char s2[]);

int main(void)
{
	char source[LENGTH], new[LENGTH];

	get_line(source, LENGTH);
//	expand(source, new);
	ans_expand(source, new);

	printf("%s", new);

	return 0;
}

/* expand: takes s1, and copies to s2, replacing [char1]-[char2] with the set of all chars from char1 to char2 */
void expand(char s1[], char s2[])
{
	//should handle
	//a-z
	//a-b-c
	//a-z0-9
	//-a-z
	//-w
	//w-
	
	//a-z implementation:
	//go from a to z
	//
	//-a implem:
	//go from 1 past a, until a
	//
	//a- imp:
	//go from a, to (excl) a
	
	int i, j, from = ' ', to = ' ';
	int l;

	for (i = j = 0; s1[i] != '\0'; ++i, ++j) { // FOR EACH CHA IN S1
//		printf("ITERATE, %d, %d\n", i, j);
		if (s1[i] == '-') {
			if (from == ' ' || from == '\t' || from == '\n') { //FROM IS WHITESPACE
				for (l = (s1[i+1]); //one char in string past current char (-), next char after that in sequence of chars
						l != s1[i+1]; ++l, ++j)
					s2[j] = l;
			} else if (s1[i+j] == ' ') { // ELSE, TO IS WHITESPACE
				for (l = from; l != from; ++l, ++j) 
					s2[j] = l;
			} else {
				for (l = ++from; l != s1[i+1]+1; ++l, ++j) {
					s2[j] = l;
				}
			}
		}
		else {
			s2[j] = s1[i]; // set char in s2 to char in s1
		}

		from = s1[i]; // set for next iteration
	}
	s2[j] = '\0';
}

void ans_expand(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0') //fetchar a char from s1[]
		if (s1[i] == '-' && s1[i+1] >= c) {
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		} else
			s2[j++] = c;
	s2[j] = '\0';

}
