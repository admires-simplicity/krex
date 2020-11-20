#include <stdio.h>

int binsearch(int x, int v[], int n);
int bsearch_v2(int x, int v[], int n);

main()
{
	int array[20] = {-2, -1, 0, 2, 3, 4, 6, 10, 11, 12, 13, 14, 15, 17, 20, 23, 29, 31, 32, 35};
	printf("%d\n", binsearch(6, array, 20));
	printf("%d\n", binsearch(12, array, 20));
	printf("%d\n", binsearch(99, array, 20));
	printf("%d\n", binsearch(35, array, 20));

	printf("%d\n", bsearch_v2(6, array, 20));
	printf("%d\n", bsearch_v2(12, array, 20));
	printf("%d\n", bsearch_v2(99, array, 20));
	printf("%d\n", bsearch_v2(35, array, 20));

}

/* find x in v[] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* MATCH */
			return mid;
	}
	return -1;	/* MATCH NONEXISTANT */
}

int bsearch_v2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		(x < v[mid]) ? (high = mid - 1) : (low = mid + 1); 	// if x lower mid, high is mid - 1, else low is mid+1
		mid = (low+high) / 2;					//mid = midpoint of high and low
	}

	if (v[mid] == x)
		return mid;
	else
		return -1;
}
