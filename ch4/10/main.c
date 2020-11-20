#include <stdio.h>

int main(void)
{
	int v[] = {3546, 52, 0, 66, -515, 543, 72, 2, 86, 234, 873, 34, 25, 674, 32, 2, 1};
	int len = 17;
	int i;
	void qsort(int [], int i, int j);

	printf("UNSORTED LIST:\n");
	for (i = 0; i < len; ++i)
		printf("elem %3d: %5d\n", i, v[i]);


	qsort(v, 0, 16);

	
	printf("\nSORTED LIST:\n");
	for (i = 0; i < len; ++i)
		printf("elem %3d: %5d\n", i, v[i]);
}
