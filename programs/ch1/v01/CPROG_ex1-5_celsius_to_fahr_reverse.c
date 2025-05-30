#include <stdio.h>

/* print Celsius-Fahrenheit table */

main()
{
    float fahr, celsius;
    int upper, lower, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("Table of Celsius to Fahrenheit, from %d to %d degrees Celsius\n", upper, lower);
    printf("Fahrenheit -- Celsius\n");
    for (celsius = upper; celsius >= lower; celsius -= step) {
	fahr = (celsius * (5.0 / 9.0)) + 32.0;
	printf("%8.1f %11.0f\n", fahr, celsius);
    }
}
