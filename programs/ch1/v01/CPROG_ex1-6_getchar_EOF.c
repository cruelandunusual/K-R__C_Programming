#include <stdio.h>

/* Verify that the expression getchar() != EOF is 0 or 1 */
main()
{
    int c;
    int count = 0;
    while ((c = getchar()) != EOF && count < 10) {
	/* putchar(c); */
	printf("%d\n", getchar() != EOF);
	count++;
    }
    /* I use the count variable to terminate the program
     without having to force quit. I think this satisfies
    the exercise - any input entered always produces 1, except
    pressing Enter by itself produces a blank line. Not the most
    meaningful input but serves to prove input is either 1 or not 1. */
}
