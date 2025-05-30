#include <stdio.h>

/* Write a program to print the number of lines in input */
main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) {
	if (c == '\n') {
	    ++nl;
	}
    }
    printf("Number of lines in input: %d\n", nl);	
}
