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
	int digits = 1; //number of digits required to write number
	int pob = 1; //some power of base
	int i; //iterator for tracking digits in reverse
	int x; //for storing value of current digit

	//calculate number of digits required to store number, and positional value of that digit space
	while ((pob *= base) <= given_value) { 	//while the current power of base is less than or equal to the given base10 value,
		++digits;			//you need another digit to store the value
	}
	pob /= base; //pob now equals base ^ digits, which is the proper value of that digit space
	
	while (given_value != 0) {
		for (i = digits; i > 0; --i, pob /= base) { //for each digit (starting from left side, counting down to right side
			x = 0; //value of this digit
			while (given_value >= pob) { //calculate how many pobs can fit in x
				++x;
				given_value -= pob;
			}
			s[digits-i] = (x < 10) ? x+'0' : x-10+'A'; //STOLEN FROM C ANSWER BOOK
		}	
	}
	s[digits] = '\0'; // if passed 0 as given value, the s[0] is left as it was.............
	//looking at the answerbook solution, it seems ~1bajillion times easier to do in reverse, then reverse it. fark it lol
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
