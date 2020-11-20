#include <stdio.h>

float to_celsius(float fahr);

/* print Fahrenheit-Celsius table
 * fo fahr = 0, 20, ..., 300 */

main()
{
	printf("Fahrenheit to Celsius table:\n");

	for (float i = 0.0; i <= 300.0; i = i + 20.0)
		printf("%3.0f %6.1f\n", i, to_celsius(i));
}

float to_celsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}
