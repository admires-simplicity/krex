#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
int wordlength(void);

main()
{
//	printf("%d\n", 200 & 127); /*should print 72*/
//	printf("%d\n", 20 >> 2); /*should print 5*/
//	printf("%d\n", getbits(251,4,3)); /*should print 6*/
//	printf("%d\n", (~0 << 2));

//	printf("%d\n", 227 & 3); 
//	printf("%d\n", (227 >> 5) << 5); 
//
//	printf("%d\n", ((255 >> 5) << 5) + (255 & 3)); 


//	printf("%d\n", setbits(227, 4, 3, 250));	// should print 235
//	printf("%d\n", setbits(148, 6, 4, 77));	// should print 236
//	printf("%d\n", setbits(0, 7, 3, 85));	// should print 160

//	printf("%d\n", invert(0, 4, 3)); //should print 28
//	printf("%d\n", invert(255, 7, 8)); // 0

	printf("%d\n", wordlength());
	printf("%d\n", rightrot(8, 1));
	//abandoning this because I don't get it and I don't really exactly know what its supposed to do and also anyway I really really don't care at all so fuck it


}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p+1-n));
}

/*rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit;		//rightmost bit
	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;		// shift x 1 position right
		x = x | rbit;		//complete one rotation
	}
	return x;
}

/*wordlength: computes word length of the machine*/
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	for (i = 1; (v = v >> 1) > 0; ++i)
		;
	return i;
}
