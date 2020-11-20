/*qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)	/* DO NOTHING */
		return;

	swap(v, left, (left + right)/2);	/* move partition elem */
	last = left;				/*to v[0] */

	for (i = left+1; i <= right; ++i)	/*partition*/ /*all between left and right*/
		if (v[i] < v[left])				/*if lower than element*/
			swap(v, ++last, i);			/*move it into the lesser partition*/

	swap(v, left, last);			/*restore partition elem*/
	qsort(v, left, last-1);		/*partition of elements lesser than partition element*/
	qsort(v, last+1, right);	/*partition of elements greater than partition element*/
}
