#include <stdio.h>

/*
  Write a program to print a histogram of the frequencies
  of different characters in its input.

  For illustration purposes the program uses the vowels.
*/

#define WORD  1 // 1 means we're inside a word
#define BLANK 0 // 0 means we're outside a word

main()
{
    int c, i, j, state, wlength, maxval, NUMVOWELS;
    NUMVOWELS = 5;
    state = BLANK;
    maxval = 0;
    int vowels[NUMVOWELS];

    for (i = 0; i < NUMVOWELS; ++i) {
	vowels[i] = 0;
    }
    
    while ((c = getchar()) != EOF ) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	}
	else if (state == BLANK) {
	    state = WORD;
	}
	if (state == WORD) {
	    if (c == 'a' || c == 'A') {
		++vowels[0];
	    }
	    else if (c == 'e' || c == 'E') {
		++vowels[1];
	    }
	    else if (c == 'i' || c == 'I') {
		++vowels[2];
	    }
	    else if (c == 'o' || c == 'O') {
		++vowels[3];
	    }
	    else if (c == 'u' || c == 'U') {
		++vowels[4];
	    }
	}
    }
    
    /* print horizontal bars */
/*    
      for (i = 0; i < 10; ++i) {
      printf("%2d - ", i+1);
      for (j = 0; j < vowels[i]; ++j) {
      printf("*");
      }
      printf("\n");
      }
      printf("\n");
*/  

    
    // print vertical bars
  
    for (i = 0; i < NUMVOWELS; ++i) {
	if (vowels[i] > maxval) {
	    maxval = vowels[i];
	}
    }
    maxval++; // increase maxval by one to correct for array indexing starting at zero
        
    for (i = maxval; i > 0; --i) {
	for (j = 0; j < NUMVOWELS; ++j) {
	    //iterate whole array, subtracting
	    //outer loop index from subscripted array value
	    if (vowels[j]-i >= 0) {
		printf(" * ");
	    }
	    else {
		printf("   ");
	    }
	}
	printf("\n");
    }

    //for (i = 0; i < NUMVOWELS; ++i) {
//	printf(" %c ", i);
    //  }
    printf(" A ");
    printf(" E ");
    printf(" I ");
    printf(" O ");
    printf(" U ");
    printf("\n");
}
