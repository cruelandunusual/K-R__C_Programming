#include <stdio.h>

#define WORD  1
#define BLANK 0

main()
{
    int c, prevc;
    int chars = 0;
    int words = 0;
    int lines = 0;
    int state = BLANK;
    
    while ((c = getchar()) != EOF) {
	++chars; // count all chars

	if (c == '\n') {
	    ++lines;
	}
	
	if (c == ' ') {
	    state = BLANK;
	}
	else {
	    state = WORD;
	}

	if (state == WORD && prevc == ' ') {
	    ++words;
	}
	prevc = c;
    }
    printf("chars, words and lines: %d, %d, %d\n", chars, words, lines);
}
