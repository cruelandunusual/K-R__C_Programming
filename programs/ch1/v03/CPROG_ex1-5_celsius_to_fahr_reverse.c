#include <stdio.h>

main()
{

    float fahr, celsius;
    float upper, lower, step;
    
    lower = 0.0;
    upper = 300.0;
    step = 20.0;
	
    for (fahr = upper; fahr >= lower; fahr -= step) {
	celsius = 5.0/9.0 * (fahr - 32.0); 
	printf("%3.0f %6.1f\n", fahr, celsius);
    }

}
