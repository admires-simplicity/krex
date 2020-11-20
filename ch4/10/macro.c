#include <stdio.h>

#define swap(t,x,y) {	\
	t _z;		\
	_z = x;		\
	x = y;		\
	y = _z;	}

int main(void)
{
	int a = 10;
	int b = 20;

	printf("%d, %d\n", a, b);
	swap(int, a, b);
	printf("%d, %d\n", a, b);
}
