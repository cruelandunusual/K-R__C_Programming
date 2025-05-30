#include <stdio.h>

/* print Fahrenheit-Celsius table */

main()
{
    float fahr, celsius;

    for (fahr = 0.0; fahr <= 300.0; fahr = fahr + 20.0) {
	celsius = 5.0/9.0 * (fahr - 32.0); 
	printf("fahr- %3.0f    celsius- %5.1f\n", fahr, celsius);
    }
    printf("Proof that the for-loop ends with fahr being greater than 300: fahr = %3.0f\n", fahr);
}
