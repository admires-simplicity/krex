#include <ctype.h>
#include "atof.h"

/*atof: convert string s to double
 * extended to handle scientific notation of form:
 * 	123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent*/
double atof(char s[])
{
	double val, power;
	int i, sign, e_sign, e_factor;

	for (i = 0; isspace(s[i]); i++) /* skip whitespace */
		;
	sign = (s[i] == '-') ? -1 : 1;				//HANDLE SIGNS
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)			//HANDLE DIGIT SEQUENCE
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')					//HANDLE DECIMAL POINT
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {			//HANDLE FRACTIONAL PART
		val = 10.0 * val + (s[i] - '0');		//KEEP ADDING FRACTIONAL PART
		power *= 10.0;					//TRACK POWER VAL IS LARGER THAN IT SHOULD BE
	}

	val = sign * val / power;				//DIVIDE POWER BY HOW OVERLARGE IT IS, * SIGN

	if (s[i] == 'e' || s[i] == 'E')				//HANDLE E
		i++;
	e_sign = (s[i] == '-') ? -1 : 1;			//HANDLE EXPONENTIAL SIGN
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (e_factor = 0; isdigit(s[i]); i++)			//GET E FACTOR
		e_factor = 10 * e_factor + (s[i] - '0');

	if (e_sign > 0) {					//FACTORIZE VALUE BY E
		while (e_factor > 0, e_factor--)
			val *= 10;
	} else {
		while (e_factor > 0, e_factor--)
			val /= 10;
	}

	return val;						//RETURN ! ! ! :)
}
