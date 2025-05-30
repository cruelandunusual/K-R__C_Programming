#include <stdio.h>

/* Write a program to copy its input to its output,
   replacing each string of one or more blanks by a single blank.
*/

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int c, currc, lastc;
    lastc = BLANK;
    
    while ( (c = getchar()) != EOF ) {
	if (c == ' ') {
	    currc = BLANK;
	}
	else {
	    currc = CHAR;
	}
	if ((currc == CHAR) || (currc == BLANK && lastc != BLANK)) {
	    putchar(c);
	}
	lastc = currc;
    }
}
