/* To illustrate difference of arrays and pointers...
 * first, strcpy(s,t), which copies string t to string s
 * it would be nice to just say, s=t, but this copies the pointer, not the characters...
 * to copy the characters, we need a loop. */

//first, array version
void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

//for contrast, pointer version
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
		//couldn't i just write:
		//++s, ++t;	???
	}
}

//in practice, experienced C programmers would prefer:
void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

//with reduced redundancy
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)	//works, because when t == '\0', then s == 0, so the loop stops...
		;
}

/*Next, strcmp(s,t). which compares character strings s and t, and returns
 * negative, zero, or positive, depending on whether the first position where s
 * != t is less, nonexistant (all s == t), or greater */
/*strcmp: return <0 if s<t, 0 if s==t, >0 if s>t*/
//array ver
int strcmp(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; ++i)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];	//if s is greater, positive returned; if s is lesser, negative returned
}

//ptr ver
int strcmp(char *s, char *t)
{
	for (; *s == *t; ++s, ++t)
		if (*s == '\0')
			return 0;
	return *s - *t;
}
