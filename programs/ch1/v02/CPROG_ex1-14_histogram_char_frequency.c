#include <stdio.h>

main()
{
    const int HIST_LENGTH = 5;
    int char_frequency[HIST_LENGTH];
    int i;
    char c;

    
    for (i = 0; i < HIST_LENGTH; ++i) {
	char_frequency[i] = 0;
    }


    while ((c = getchar()) != EOF) {
	if (c == 'a' || c == 'A') {
	    ++char_frequency[c == 'a'? c-'a': c-'A'];
	}
	else if (c == 'e' || c == 'E') {
	    ++char_frequency[c == 'e'? (c-'e')+1: (c-'E')+1];
	}
	else if (c == 'i' || c == 'I') {
	    ++char_frequency[c == 'i'? (c-'i')+2: (c-'I')+2];
	}
	else if (c == 'o' || c == 'E') {
	    ++char_frequency[c == 'o'? (c-'o')+3: (c-'O')+3];
	}
	else if (c == 'u' || c == 'U') {
	    ++char_frequency[c == 'u'? (c-'u')+4: (c-'U')+4];
	}
	
    }

    int max_value = 0;
    for (i = 0; i < HIST_LENGTH; ++i) {
	if (char_frequency[i] > max_value) {
	    max_value = char_frequency[i];
	}
    }
    
    int j;

    //print histogram right way up
    for (i = max_value; i > 0; --i) {
	for (j = 0; j < HIST_LENGTH; ++j) {
	    if (char_frequency[j] >= i) {
		printf(" * ");
	    }
	    else printf(" - ");
	}
	printf("\n");
    }    
    
    printf("\n");
    
}
