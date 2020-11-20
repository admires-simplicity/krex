#include <stdio.h>

/* print Celsius-Fahrenheit table
 * fo fahr = 0, 20, ..., 300 */

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	// lower limit of temperature table
	upper = 300;	// upper limit
	step = 20;	// step size

	printf("Celsius to Fahrenheit table:\n");

	celsius = lower;
	while(celsius <= upper) {
		fahr = ((9.0 * celsius) / 5) + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
