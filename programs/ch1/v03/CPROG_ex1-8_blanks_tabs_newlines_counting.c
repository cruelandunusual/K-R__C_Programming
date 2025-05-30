#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

main()
{
    int c;
    int bl, tb, nl;
    bl = tb = nl = 0;

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
    printf("Number of blanks, tabs and newlines:\n%d, %d, %d\n", bl, tb, nl);
    
}
