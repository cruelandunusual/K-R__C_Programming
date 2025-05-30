#include <stdio.h>

/* Verify that the expression getchar() != EOF is 0 or 1. */

main()
{
    int c;
    while (c = getchar() != EOF) {
	/*
	  if EOF is -1 and getchar() returns a positive value (e.g. 97, or 'a',
	  then (getchar() != EOF) is a true statement, which means c is assigned
	  the value 1, so the if statement below will be entered.
	 */
	if (c == 1) { //this could also be if (c) { }
	    printf("getchar() != EOF, so c == %d\n", c);
	}
    }
    printf("now c = %d\n", c);
}

/*
  Actually, this program doesn't work as intended. The expression
  c = getchar() != EOF seems to set c to the value returned by getchar(),
  not to the boolean value 1 or 0.
  Also, I get strange behaviour depending on whether or not I use
  putchar(c) or printf("%d",c) in the if statement that follows.
  When I use printf the if statement seems to be entered, and the printf
  is executed. When I use putchar the if statement doesn't seem to be entered,
  and the only output of the entire program is the final if statement at the end.
 */
