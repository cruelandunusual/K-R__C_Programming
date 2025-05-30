#include <stdio.h>

/*
  count lines, words and characters in input
*/

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int c, nl, nw, nc;
    nl = nw = nc = 0;
    int state;
    state = BLANK;
    
    while ((c = getchar()) != EOF ) {
	++nc;
	if (c == '\n') {
	    ++nl;
	}
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	}
	else if (state == BLANK) {
	    state = CHAR;
	    ++nw;
	}
    }
    printf("number of characters: %d\n", nc);
    printf("number of words: %d\n", nw);
    printf("number of lines: %d\n", nl);
}
