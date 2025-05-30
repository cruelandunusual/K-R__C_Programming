#include <stdio.h>

/* Write a program to print the number of characters in input */
main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc) {
	;
    }
    printf("Number of characters in input: %.0f\n", nc);	
}
