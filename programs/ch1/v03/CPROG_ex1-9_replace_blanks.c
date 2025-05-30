#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output,
   replacing each string of one or more blanks by a single blank. */

main()
{
    int c;
    int prevc;
    prevc = 0;
    while ((c = getchar()) != EOF) {
	if (c != ' ') {
	    putchar(c); //print everything that's NOT a space
	}
	else if (c == ' ' && prevc != c) {
	    putchar(c); /* putchar() called twice in this solution
			 -- not good*/
	}
	prevc = c;
    }
}

/*
  Following is pasted in from my own v1 solution.
  I seem to remember I didn't come up with this on my own.
  My v2 solution is more basic, like my v3 above.
  However, while writing my v3 I was nagged with the idea
  that the putchar() statement should be called only once,
  so I was remembering, or perhaps re-figuring out, that
  the best way to solve it was to store a state.
*/
/*
#define CHAR     1
#define BLANK    0

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
*/
