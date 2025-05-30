#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300
   using the conversion formula
   C=(5/9)(F-32)
*/

int fahr_to_celsius(int fahr) {
    int celsius = 5 * (fahr-32) / 9;
    return celsius;
}

main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temperature scale */
    upper = 300;/* upper limit */
    step = 20;/* step size */

    fahr = lower;
    while (fahr <= upper) {
	celsius = fahr_to_celsius(fahr);
	printf("%d\t%d\n", fahr, celsius);
	fahr = fahr + step;
    }
}
