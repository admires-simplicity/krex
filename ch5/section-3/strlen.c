/*strlen: return length of string s */
int strlen(char *s)			//what is passed is a pointer to the first character in a string
{
	int n;

	for (n = 0; *s != '\0'; ++s)	//check next char in string
		++n;
	return n;
}
 
// ALL WORK:
// strlen("hello, world");	//string constant
// strlen(array);			//char array[100];
// strlen(ptr);			//char *ptr;
