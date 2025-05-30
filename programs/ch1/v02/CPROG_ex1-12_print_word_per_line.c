#include <stdio.h>

#define CHAR  1
#define BLANK 0

main()
{
    int c, lastc;
    lastc = 0;
    int state = BLANK;
    while ((c = getchar()) != EOF)
    {
	if (c == ' ' && c != lastc)
	{
	    putchar('\n');
	    state = BLANK;
	}
	else if (c == ' ' && c == lastc)
	{
	    continue;
	}
	else if (state == BLANK)
	{
	    putchar(c);
	    state = CHAR;
	}
	lastc = c;
    }
}
