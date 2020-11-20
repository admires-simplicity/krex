#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void rreverse(char s[]);

int main(void)
{
	char s[] = "Hola, amicus meus!\0";

	printf("String is: \"%s\"\n", s);
	rreverse(s);
	printf("Revers is: \"%s\"\n", s);

}

/*recursive version of reverse function*/
void rreverse(char s[])
{
	void reverser(char s[], int i, int len);

	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	int c, j;
	j = len - (i+1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
		c = s[i];
		s[i] = s[j];
		s[j] = s[i];
	}
}
