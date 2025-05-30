#include <stdio.h>

/*
  count lines, words and characters in input
*/

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int c;
    int state;
    state = BLANK;
    
    while ((c = getchar()) != EOF ) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	}
	else if (state == BLANK) {
	    state = CHAR;
	    putchar('\n');
	}
	putchar(c);
    }
}
