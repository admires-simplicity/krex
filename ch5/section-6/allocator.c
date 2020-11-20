#define ALLOCSIZE 10000	/*size of available space*/

static char allocbuf[ALLOCSIZE];	/*storage for alloc*/
static char *allocp = allocbuf;		/*next free position*/ /* equivalent to: static char *allocp = &allocbuf[0]*/

char *alloc(int n)			/*return pointer to n characters*/ /*return pointer to char in allocbuf, from which there are n free consequitive chars*/
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/*it fits*/ /*check if room to satisfy request for n characters*/
		allocp += n;				/*allocp, which points to the next free position, incremented by n*/
		return allocp - n;	/*old p*/ 	/*first char which was allocated by this function call, is the old allocp*/
	} else	/*not enough room*/	
		return 0;		/*C guarantees that 0 is never a valid address for data, so it's appropriate as an error signal*/
}

void afree(char *p)	/*free storage pointed to by p*/
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) /*pointer p is past allocbuf[0], and less than allocbuf[10000], therefor, within thoe bounds of allocbuf*/
		allocp = p; /*next free position equals p*/
}
