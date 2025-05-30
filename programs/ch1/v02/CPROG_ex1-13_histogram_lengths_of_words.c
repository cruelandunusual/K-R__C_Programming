#include <stdio.h>

#define BLANK 0
#define CHAR  1

main()
{
    const int HIST_LENGTH = 10;
    int word_length_hist[HIST_LENGTH];
    int i, c, word_size, state;
    state = BLANK;
    word_size = 0;
    
    for (i = 0; i < HIST_LENGTH; ++i) {
	word_length_hist[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = BLANK;
	    if (word_size > 0) {
		if (word_size > HIST_LENGTH) {
		    word_size = HIST_LENGTH;
		}
		++word_length_hist[word_size-1];//subtract 1 for correct array indexing
	    }
	    word_size = 0;
	}
	
	else if (state == BLANK) {
	    state = CHAR;
	}
	
	if (state == CHAR) {
	    ++word_size;
	}
    }

    int max_value = 0;
    for (i = 0; i < HIST_LENGTH; ++i) {
	if (word_length_hist[i] > max_value) {
	    max_value = word_length_hist[i];
	}
    }
    
    int j;

    /*
      //print histogram upside down
    for (i = 0; i < max_value; ++i) {
	for (j = 0; j < HIST_LENGTH; ++j) {
	    if (word_length_hist[j] > i) {
		printf(" * ");
	    }
	    else printf(" - ");
	}
	printf("\n");
    }
    */

    //print histogram right way up
    for (i = max_value; i > 0; --i) {
	for (j = 0; j < HIST_LENGTH; ++j) {
	    if (word_length_hist[j] >= i) {
		printf(" * ");
	    }
	    else printf(" - ");
	}
	printf("\n");
    }    
    
    printf("\n");
}
