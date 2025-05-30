#include <stdio.h>

int fahr_to_celsius(int fahr);

main()
{
    int fahr;
    int lower, upper, step;

    fahr = lower = 0;
    step = 20;
    upper = 300;
    while (fahr <= upper) {
	printf("fahr = %3d, celsius = %3d\n", fahr, fahr_to_celsius(fahr));
	fahr += step;
    }
    return 0;
}

int fahr_to_celsius(int fahr)
{
    return 5 * (fahr-32) / 9;
}
