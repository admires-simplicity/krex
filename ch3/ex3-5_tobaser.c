#include <stdio.h>
#include "helpers.h"

void itob(int n, char s[], int b);
int stoi(char s[]);

int main(void)
{
	char number[LENGTH], base[LENGTH];
	int n, b;

	printf("Enter a number: ");
	get_line(number, LENGTH);
	n = stoi(number);

	printf("Enter base to convert to: ");
	get_line(base, LENGTH);
	b = stoi(base);

	itob(n, number, b);
	printf("%s\n", number);
	
}

void itob(int given_value, char s[], int base) {
	int digits = 1;
	int pob = 1; //base ^ digits, which is equal to base ^ (what this digits from rightside should be + 1) [name means 'power of base']
	int i; //iterator for tracking digits in reverse
	int x;

	//we need d digits, where b ^ d * b is greater than n
	//in base 16, 1 digits can hold up to 15

	while ((pob *= base) <= given_value) {//power of base is 1 greater than max val storable in digits digits base base number, so
		++digits;				//if max val is not less than pob, you need more at least another digits
	}
	pob /= base;
	
	printf("NUMBER OF DIGITS REQUIRED: %d\n", digits);
	printf("POWER OF BASE: %d\n", pob);
	// in base 5,
	// 4 -> pob = 5		5^1 (1 digits req'd, prints 1) NOW 0, 1
	// 5 -> pob = 25	5^2 (2 digits req'd, prints 2) NOW 1, 5 
	// 26 -> pob = 125	5^3 (3 digits req'd, prints 3) NOW 2, 25
	
	if (given_value == 0) {
		s[0] == '0';
		s[1] == '\0';
	} else {
		while (given_value != 0) {
			for (i = digits; i > 0; --i, pob /= base) {
				x = 0;
				while (given_value >= pob) {
					++x;
					given_value -= pob;
				}
				s[digits-i] = '0' + x; //doesn't handle >9 right, fix l8r
			}	
		}
		s[digits] = '\0';
	}
}

int stoi(char s[]) {
	int n = 0;
	int i = 0;

	while (s[i] != '\n') { //because my function get_line always ends strings with \n \0
		n *= 10;
		n += (s[i++] - '0');
	}

	return n;
}
