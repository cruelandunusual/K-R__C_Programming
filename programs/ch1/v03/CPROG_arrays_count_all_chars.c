#include <stdio.h>

/* count digits, whitespace, others */

#define OFFSET '0'
main()
{
    int c, i, nwhitespace, nother;
    nwhitespace = nother = 0;
    int ndigit[10];
    
    for (i = 0; i < 10; ++i) { 	/* initialise array to zero */
	ndigit[i] = 0;
    }

    for (i = 0; (c = getchar()) != EOF; ++i) {
	if (c >= '0' && c <= '9') {
	    ++ndigit[c-OFFSET];
	}
	else if (c == ' ' || c == '\t' || c == '\n') {
	    ++nwhitespace;
	}
	else ++nother;
    }
    printf("number of whitespace characters: %d\n", nwhitespace);
    printf("number of digits:\n");
    for (i = 0; i < 10; ++i) {
	printf("%d: %d\n", i, ndigit[i]);
    }
    printf("number of all other characters: %d\n", nother);
}
