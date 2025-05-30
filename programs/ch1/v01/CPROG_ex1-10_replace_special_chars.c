#include <stdio.h>

/*
  Write a program to copy its input to its output, replacing each tab by \t, each
  backspace by \b, and each backslash by \\.
  This makes tabs and backspaces visible in an unambiguous way.
*/

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int c, tab, backslash, backspace;
    tab = backslash = backspace = 0;
    
    while ( (c = getchar()) != EOF ) {
	if (c == '\t') {
	    putchar('\\');
	    putchar('t');
	}
	else if (c == '\b') {
	    putchar('\\');
	    putchar('b');
	}
	else if (c == '\\') {
	    putchar('\\');
	    putchar('\\');
	}
	else {
	    putchar(c);
	}
    }
}
