#include <stdio.h>

#define LOWER 0.0 /* lower limit of temperature conversion */
#define UPPER 300.0 /* upper limit of temperature conversion */
#define STEP 20.0 /* step size for printing table */


main()
{
    printf("Table of Fahrenheit to Celsius, from %0.0f to %0.0f degrees Fahrenheit\n", LOWER, UPPER);
    printf("Fahrenheit -- Celsius\n");

    float fahr, celsius;
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
	celsius = (fahr - 32) * 5.0/9.0;
	printf("%8.0f %12.1f\n", fahr, celsius);
    }
}
