#include <stdio.h>

#define a 0
#define e 1
#define i 2
#define o 3
#define u 4
#define SIZE 5

main()
{
    int vowels[SIZE];		/* stores number of vowels in text */
    int c;			/* char input from getchar() - will also be used as array initialiser index */
    
    for (c = 0; c < SIZE; ++c) { /* zero-initialise array values */
	vowels[c] = 0;
    }
    
    while ((c = getchar()) != EOF) {
	if (c == 'a' || c == 'A') {
	    ++vowels[a];
	}
	else if (c == 'e' || c == 'E') {
	    ++vowels[e];
	}
	else if (c == 'i' || c == 'I') {
	    ++vowels[i];
	}
	else if (c == 'o' || c == 'O') {
	    ++vowels[o];
	}
	else if (c == 'u' || c == 'U') {
	    ++vowels[u];
	}
    }

    printf("histogram of vowel frequency:\n");
    /* print horizontally */
    int y;			/* inner loop counter */
    for (c = 0; c < SIZE; ++c) {
	if (c == 0) printf("a - ");
	else if (c == 1) printf("e - ");
	else if (c == 2) printf("i - ");
	else if (c == 3) printf("o - ");
	else if (c == 4) printf("u - ");
	for (y = 0; y < vowels[c]; ++y) {
	    printf(" * ");
	}
	printf("\n");
    }

    /* print vertically */
    /* first need to find the largest value in the array */
    int max = 0;
    for (c = 0; c < SIZE; ++c) {
	if (vowels[c] > max) {
	    max = vowels[c];	/* max stores highest value yet found */
	}
    }

    for (c = max; c > 0; --c) {
	for (y = 0; y < SIZE; ++y) {
	    if (vowels[y] < c) {
		printf(" - ");
	    }
	    else printf(" * ");
	}
	printf("\n");
    }
    printf(" a  e  i  o  u\n");
}
