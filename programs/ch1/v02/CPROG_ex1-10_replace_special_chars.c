#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
	if (c == '\t')
	{
	    putchar('\\');
	    putchar('t');
	}l
	else if (c == '\b')
	{
	    putchar('\\');
	    putchar('b');
	}
	else if (c == '\\')
	{
	    putchar('\\');
	    putchar('\\');
	}
	else
	    putchar(c);
    }
}
