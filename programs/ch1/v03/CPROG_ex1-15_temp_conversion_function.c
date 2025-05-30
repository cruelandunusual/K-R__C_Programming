#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300
   using the conversion formula
   C=(5/9)(F-32)
*/

float fahr_to_celsius(int fahr); /* returns float for accuracy */

int main()
{
    /* test function fahr_to_celsius() */
    int i;
    for (i = 0; i < 300; i+=20) {
	printf("%3d degrees F expressed as Celsius is: %3.2f\n", i, fahr_to_celsius(i));
    }
    printf("90 degrees F expressed as Celsius is: %3.2f\n", fahr_to_celsius(90));
}

/*
  returns float for accuracy, though parameter is an int since
  most values requiring conversion will be simple whole numbers
*/
float fahr_to_celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
