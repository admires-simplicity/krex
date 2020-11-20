int strlen(char *s)	//some data location
{
	char *p = s;	//some data location, copy

	while (*p != '\0')
		++p;	//increment p
	return p - s;	//amount p has increased since copying from s, therefor distance from s to p
}
