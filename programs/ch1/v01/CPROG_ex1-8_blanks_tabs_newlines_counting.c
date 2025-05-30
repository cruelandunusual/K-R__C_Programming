#include <stdio.h>

/* Write a program to print the number of blanks,
   tabs and newlines in input */

main()
{
    int c, bl, nl, tb;
    nl = bl = tb = 0;
    
    while ((c = getchar()) != EOF) {
	if (c == ' ') {
	    ++bl;
	}
	else if (c == '\t') {
	    ++tb;
	}
	else if (c == '\n') {
	    ++nl;
	}
    }
    printf("Number of blanks in input: %d\n", bl);
    printf("Number of tabs in input: %d\n", tb);
    printf("Number of newlines in input: %d\n", nl);
}
