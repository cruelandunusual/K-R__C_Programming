#include <stdio.h>

/* Write a program to print the number of lines in input */

main()
{
    int nl;
    nl = 0;
    
    int c;

    while ((c = getchar()) != EOF) {
	if (c == '\n') {
	    ++nl;
	}
    }
    printf("Number of lines: %d\n", nl);
}
