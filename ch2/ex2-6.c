#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

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


	printf("%d\n", setbits(227, 4, 3, 250));	// should print 235
	printf("%d\n", setbits(148, 6, 4, 77));	// should print 236
	printf("%d\n", setbits(0, 7, 3, 85));	// should print 160
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	int a, b, c;

	a = (x >> (p+1)) << (p+1);
	b = (y & (((1 << (n)) - 1))) << (p+1-n);
	c = x & ((1 << (n-1)) - 1);

//	printf("%d\n", a);
//	printf("%d\n", b);
//	printf("%d\n", c);
	return a + b + c;
}

