
//write a pointer version of the function strcat that we showed in chapter 2: strcat(s, t) copies the string t to the end of s.
//pg 119
//
#include <stdio.h>
#include <string.h>

void mypstrcat(char *s, char *t);
int strend(char *s, char *t);
void pv3_strcpy(char *s, char *t);
void my_strncopy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_ass_strcmp(char *s, char *t);
int my_strncmp(char *s, char *t, int n);

int main(void)
{
	char s1[1000] = "nice "; 	//strlen == 5	//'\0' not included
	char s2[] = "string";		//strlen == 6	//'\0' not included
	char s3[] = "awesome string";
	char s4[] = "neat";

	int x = strlen(s1);
	int y = strlen(s2);

	printf("%d, %d\n", x, y);

	mypstrcat(s1, s2);//WERX RIGHT

	printf("%s\n", s1);

	printf("%s ends with %s: %d\n", s3, s4, strend(s3, s4));//WERX RIGHT
	printf("%s ends with %s: %d\n", s3, s2, strend(s3, s2));//WERX RIGHT
	printf("%s ends with %s: %d\n", s2, s3, strend(s2, s3));//WERX RIGHT


	my_strncat(s1, s3, 7);		//WERX RIGHT
	printf("%s\n", s1); 

	my_strncopy(s1, s4, 3);	//seems 2 werx???
	printf("%s\n", s1); 
	

	printf("COMPARE %d CHARS OF:\n%s\n%s\nresult: %d\n", 3, s1, s4, my_strncmp(s1, s4, 3));
	printf("COMPARE %d CHARS OF:\n%s\n%s\nresult: %d\n", 5, s3, s1, my_strncmp(s3, s1, 5));
	printf("%d\n", my_ass_strcmp(s3, s1));

}


/*CHAPTER 2 VERSION*/
/*strcat: concatenate t to the end of s; s must be big enough*/
//void strcat(char s[], char t[])
//{
//	int i, j;
//
//	i = j = 0;
//	while (s[i] != '\0')	//find end of s
//		++i;
//	while ((s[i++] = t[j++]) != '\0') //copy t
//		;
//}

//POINTER VERSION
void mypstrcat(char *s, char *t)
{
	while (*s)	//WHILE WHAT S POINTS TO IS NOT 0
		++s;	//iterate until '\0' is found

	while (*t)	//WHAT WHAT T POINTS TO IS NOT 0
		*s++ = *t++;	//MAKE WHAT S POINTS TO EQUAL TO WHAT T POINTS TO, THEN INCREMENT BOTH
}

/*strend: returns 1 if the string t occurs at the end of the string s, and zero otherwise*/
int strend(char *s, char *t)
{
	int i, j, k;
	i = strlen(s);
	j = strlen(t);
	k = j;

	if (j > i)
		return 0;	//could be -1 to signify ???

	for ( ; i > 0; --i, ++s)	//increment s to end of s 
		;
	for ( ; k > 0; --k, ++t)	//increment t to end of t
		;

	for ( ; j > 0; j--)		//for each char in t
		if (*s-- != *t--)	//if chars not equal
			return 0;

	return 1;			//else, ends must be equal...
}

//strncpy, strncat, and strncmp
//strncpy: copy, at most n characters from t to s
//strncat: concatenate at most, n characters from t to s
//strncmp: compare, at most, n characters in strings s and t
//problem def page 119
//appendix b, page 251
//string.h... page 259


//strcpy, pointer version 3
void pv3_strcpy(char *s, char *t)
{
	while (*s++ == *t++)
		;
}

//strncpy: copy at most n characters of string t to s. Pad with '\0's if t has fewer than n characters.
void my_strncopy(char *s, char *t, int n)
{	
	for ( ; n > 0; --n)
		if (*t)
			*s++ = *t++;
		else
			*s++ = '\0';
}

//wtf, i just wrote my_strncat instead of my_strncopy ........... wtf brah
///////message from the future... lol of course, i didn't copy the code when I srote strncopy, but I literally wrote the exact identical code... the answer book literally calls strncopy for strncat.... xdxdxdxdxdxdxdxd
void my_strncat(char *s, char *t, int n)
{
	while (*s)
		s++;	//make s point to '\0'

	for ( ; n > 0; --n) {
		if (*t)
			*s++ = *t++;
		else
			*s++ = '\0';
	}

}

//ptr ver
int my_ass_strcmp(char *s, char *t)
{
	for (; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}


int my_strncmp(char *s, char *t, int n)
{
	for ( ; n > 0, *s == *t; --n, ++s, ++t) //that's fucked lol
		if (*s != '\0')
			return 0;
	return *s - *t;
}



///////////////////* THESE SOLUTIONS FROM THE C ANSWER BOOK...
////////////////// * THEY ARE PRETTY GOOD
////////////////// *
////////////////// *
////////////////// * COOL*/
//////////////////
//////////////////
//////////////////void ans_strncpy(char *s, char *t, int n)
//////////////////{
//////////////////	while (*t && n-- > 0)
//////////////////		*s++ = *t++;
//////////////////	while (n-- > 0)
//////////////////		*s++ = '\0';
//////////////////}
//////////////////
//////////////////void ans_strncat(char *s, char *t, int n)
//////////////////{
//////////////////	void strncpy(char *s, char *t, int n);
//////////////////	int strlen(char *);
//////////////////
//////////////////	ans_strncpy(s+strlen(s), t, n); //XD:w
//////////////////}
//////////////////
//////////////////int ans_strncmp(char *s, char *t, int n)		//less obfuscated therefor intellectual ... . . .. ... .... ... .. . . . . . . . . .
//////////////////{
//////////////////	for ( ; *s == *t; ++s, ++t)
//////////////////		if (*s == '\0' || --n <= 0)
//////////////////			return 0;
//////////////////	return *s - *t;
//////////////////}
