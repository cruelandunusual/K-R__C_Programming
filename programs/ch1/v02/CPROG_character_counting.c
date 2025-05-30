#include <stdio.h>

main()
{
    int c;
    int nc = 0;
    while ((c = getchar()) != EOF)
    {
	++nc;
    }
    --nc;//subtract 1 so as not to count carriage return
    printf("number of characters entered: %d\n", nc);
}
