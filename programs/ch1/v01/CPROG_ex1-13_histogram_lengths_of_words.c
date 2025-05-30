#include <stdio.h>

/*
  Use an array to store a histogram of the lengths
  of words in input to the program.
*/
#define WORD  1 /* 1 means we're inside a word */
#define BLANK 0 /* 0 means we're outside a word */

main()
{
    int c, i, j, state, wlength, maxval;
    state = BLANK;
    maxval = 0;
    wlength = 0;
    int wordlength[10];

    for (i = 0; i < 10; ++i) {
	wordlength[i] = 0;
    }
    
    while ((c = getchar()) != EOF ) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	    if (wlength > 0) {
		if (wlength > 10) {
		    wlength = 10;
		}
		++wordlength[wlength-1];
	    }
	    wlength = 0;
	}
	else if (state == BLANK) {
	    state = WORD;
	}
	if (state == WORD) {
	    ++wlength;
	}
    }
    
    /* print horizontal bars */
/*    
      for (i = 0; i < 10; ++i) {
      printf("%2d - ", i+1);
      for (j = 0; j < wordlength[i]; ++j) {
      printf("*");
      }
      printf("\n");
      }
      printf("\n");
*/  

    
    /* print vertical bars */
  
    for (i = 0; i < 10; ++i) {
	if (wordlength[i] > maxval) {
	    maxval = wordlength[i];
	}
    }
    maxval++; /* increase maxval by one to correct for array indexing starting at zero */
        
    for (i = maxval; i > 0; --i) {
	for (j = 0; j < 10; ++j) {
	    //iterate whole array, subtracting
	    //outer loop index from subscripted array value
	    if (wordlength[j]-i >= 0) {
		printf(" * ");
	    }
	    else {
		printf("   ");
	    }
	}
	printf("\n");
    }

    for (i = 0; i < 10; ++i) {
	printf(" %d ", i+1);
    }
    printf("\n");

  
}
