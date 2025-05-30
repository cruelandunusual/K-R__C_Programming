#include <stdio.h>

main()
{
    int bl = 0;
    int tb = 0;
    int nl = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
	if (c == ' ')
	    ++bl;
	
	else if (c == '\t')
	    ++tb;

	else if (c == '\n')
	    ++nl;	
    }
    printf("Number of blanks:%d\n", bl);
    printf("Number of tabs:%d\n", tb);
    printf("Number of newlines:%d\n", nl);
}
