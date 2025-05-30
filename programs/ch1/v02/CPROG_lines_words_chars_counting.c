#include <stdio.h>

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int lines, words, chars;
    lines = words = chars = 0;
    char state = BLANK;
    char c;

    while ((c = getchar()) != EOF)
    {
	if (c == '\n')
	{
	    ++lines;
	}
	if (c == ' ' || c == '\n' || c == '\t')
	{
	    state = BLANK;
	}
	else if (state == BLANK)
	{
	    ++words;
	    ++chars;
	    state = CHAR;
	}
	else if (state == CHAR)
	{
	    ++chars;
	}
    }
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of chars: %d\n", chars);
}
