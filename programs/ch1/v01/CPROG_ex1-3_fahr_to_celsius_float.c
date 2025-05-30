#include <stdio.h>

/* print Fahrenheit-Celsius table */

main()
{
    float fahr, celsius;
    float upper, lower, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    printf("Table of Fahrenheit to Celsius, from %.0f to %.0f degrees Fahrenheit\n", lower, upper);
    printf("Fahrenheit -- Celsius\n");
    fahr = lower;
    while (fahr <= upper) {
	/* celsius = 5.0 * (fahr - 32.0) / 9.0; */
	celsius = (5.0 / 9.0) * (fahr - 32.0);
	printf("%6.0f %13.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
}
