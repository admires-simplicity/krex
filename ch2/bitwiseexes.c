#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

main()
{
	printf("%d\n", 200 & 127); /*should print 72*/
	printf("%d\n", 20 >> 2); /*should print 5*/
	printf("%d\n", getbits(251,4,3)); /*should print 6*/
	printf("%d\n", (~0 << 2));
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
