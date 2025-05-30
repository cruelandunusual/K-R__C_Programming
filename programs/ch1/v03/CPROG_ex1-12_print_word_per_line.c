#include <stdio.h>

/* Write a program that prints its input one word per line. */

#define BLANK 0
#define WORD  1

main()
{
    int c;
    int state = BLANK;
    int prevstate = BLANK;
    
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	}
	else state = WORD;
	if (state == BLANK && prevstate == WORD) {
	    putchar('\n');
	}
	else putchar(c);
	prevstate = state;
    }
}
