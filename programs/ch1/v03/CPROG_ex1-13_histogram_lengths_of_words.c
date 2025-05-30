#include <stdio.h>

/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#define OFFSET 1

#define SPACE 0
#define WORD  1

main()
{
    int c;			/* current char from getchar() */
    int word_histogram[10]; 	/* array[0]-[9] stores words of length 1-10+ */
    int word_length;		/* length of current word */
    int state;			/* = WORD if inside a word, SPACE if outside */
    int y;			/* inner for-loop counter (for printing the histograms)  */
    int i;			/* for-loop counter */    
    for (i = 0; i < 10; ++i) {	/* zero-initialise array values */
	word_histogram[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { /* current char is a letter */
	    state = WORD;
	    ++word_length;
	    if (word_length > 10) {
		word_length = 10;
	    }
	}
	else if (state == WORD) {
	    state = SPACE;
	    ++word_histogram[word_length - OFFSET];
	    word_length = 0;
	}
    }
    
    /* horizontal printing */
    
    /* printf("word length histogram:\n"); */
    /* for (i = 0; i < 10; ++i) { */
    /* 	printf("%2d - ", i+1); */
    /* 	for (y = 0; y < word_histogram[i]; ++y) { */
    /* 	    printf("*"); */
    /* 	} */
    /* 	printf("\n"); */
    /* } */

    /* vertical printing */
    /* first we need to find the largest element in the array */
    int max = 0;
    for (i = 0; i < 10; ++i) {
	if (word_histogram[i] > max) {
	    max = word_histogram[i]; /* store the largest element yet found in max */
	}
    }
    /* this is the printing part of the algorithm proper */
    for (y = max; y > 0; --y) {	/* outer loop is set by max value; this is the 'height' */
	for (i = 0; i < 10; ++i) { /* inner loop (each horizontal line printing) is set by length of array */
	    if (word_histogram[i] < y) {
		printf("   ");	/* print a dash if no value here */
	    }
	    else printf(" * ");	/* print a star if value found */
	}
	printf("\n");
    }
    printf(" 1  2  3  4  5  6  7  8  9  10\n");
}
