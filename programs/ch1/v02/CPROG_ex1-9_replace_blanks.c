#include <stdio.h>

#define CHAR     1    /*  */
#define BLANK    0    /*  */

main()
{
    int c, lastc;
    lastc = CHAR;

    while ((c = getchar()) != EOF)
    {
	if (c == ' ' && lastc == CHAR)
	{
	    putchar(c);
	    lastc = BLANK;
	}
	else if (c != ' ')
	{
	    putchar(c);
	    lastc = CHAR;
	}
    }
}
