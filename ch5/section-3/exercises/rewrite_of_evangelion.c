//Rewrite appropriate programs with pointers instead of array indexing:
//getline [Chapters 1 and 4]
//atoi, itoa, and variants [Chapters 2, 3, 4]
//reverse [Chapter 3]
//strindex and getop [Chapter 4]
//description of exersise: PG. 119

//Getline, from Chapter 1, PG 41
int getline(char s[], int lim)
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

//Getline, from Chapter 4, PG 81
int getline(char s[], int lin)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

//POINTER VERSION
int getline(char *s, int lim)
{
	int c, i;

	i = 0;	//COULD USE *t THEN SUBTRACT s - t...........
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;	//the thing which s points to is equal to c, then incrememnt s
	if (*s == '\n')
		*s++ = c;	//the thing which s points to is equal to c, then incrememnt s
	*s = '\0';
	return i;
}

//atoi, PAGE 73
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); ++i)	//skip whitespace
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')	//skip sign
		++i;
	for (n = 0; isdigit(s[i]); ++i)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
//itoa, PAGE 76
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	//record sign
		n = -n;		//set n positive
	i = 0;
	do {	//generate digits in reverse order
		s[i++] = n % 10 + '0';	//get next digit
	} while ((n /= 10) > 0);	//delete it
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

//atoi, pointer ver
int atoi(char *s)
{
	int n, sign;

	while (isspace(*s))	//skip whitespace
		++s;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')	//skip sign
		++s;
	for (n = 0; isdigit(*s); ++s)
		n = 10 * n + (*s - '0');
	return sign * n;
}
//itoa, PAGE 76
void itoa(int n, char s[])
{
	int sign;

	if ((sign = n) < 0)	//record sign
		n = -n;		//set n positive
	do {	//generate digits in reverse order
		*s++ = n % 10 + '0';	//get next digit
	} while ((n /= 10) > 0);	//delete it
	if (sign < 0)
		*s++ = '-';
	*s = '\0';
	reverse(s);
}

///whateverman I think i get it........
