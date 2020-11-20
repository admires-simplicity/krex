#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*day_of_year: set day of year from month & day*/
//Return #day of year, based on input Y M D.
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *pdt;
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
		return -1;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	pdt = (daytab[leap])+1;

	for (i = 1; i < month; i++)
		day += *pdt++;
	return day;
}

/*month_day: set month, day, from day of year*/
//Set #of month and #of day to pmonth and pday, based on year and yearday
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *pdt;
	if (yearday < 1 || yearday > 366 || year < 1) {
		*pmonth = -1;
		*pday = -1;
		return;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	pdt = (daytab[leap]) + 1;

	while (yearday > *pdt)
		yearday -= *pdt++;

	*pmonth = (sizeof(pdt) / sizeof(*pdt)) + 1; //i think there are other ways to do this, and i was trying to figure them out for a while, but i couldnt so fugg et
	*pday = yearday;
}

int main(void)
{
	int y,m,d,yd;

	printf("NORMAL CASE TESTS:\n");

	y = 2005;
	m = 1;
	d = 1;
	printf("%4d/%2d/%2d : %3d-th day of year\n", y,m,d, day_of_year(y,m,d));

	y = 2055;
	m = 7;
	d = 3;
	printf("%4d/%2d/%2d : %3d-th day of year\n", y,m,d, day_of_year(y,m,d));
	
	y = 2056;
	m = 7;
	d = 3;
	printf("%4d/%2d/%2d : %3d-th day of year\n", y,m,d, day_of_year(y,m,d));
	
	y = 2057;
	m = 7;
	d = 3;
	printf("%4d/%2d/%2d : %3d-th day of year\n", y,m,d, day_of_year(y,m,d));

	y = 2048;
	yd = 256;
	month_day(y, yd, &m, &d);
	printf("%3d-th day of %4d is: %4d/%2d/%2d\n", yd, y, y, m, d);


	printf("ERROR CASE TESTS:\n");
	
	y = 2004;
	m = 13;
	d = 1;
	printf("%4d/%2d/%2d : %3d-th day of year\n", y,m,d, day_of_year(y,m,d));

	y = 69;
	yd = 420;
	month_day(y, yd, &m, &d);
	printf("%3d-th day of %4d is: %4d/%2d/%2d\n", yd, y, y, m, d);

}
