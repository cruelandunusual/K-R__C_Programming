#include <stdio.h>

main()
{
    double nc = 0;
    char c;
    for (nc = 0; (c = getchar()) != EOF; ++nc)
    {
	;
    }
    printf("Number of characters entered: %.0f\n", nc);
}
