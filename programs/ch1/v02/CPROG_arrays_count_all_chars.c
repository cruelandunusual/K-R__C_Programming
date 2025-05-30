#include <stdio.h>

/* count digits, whitespace, others */

main()
{
    int c, i, nwhitespace, nother;
    nwhitespace = nother = 0;
    int ndigit[10];

    for (i = 0; i < 10; ++i)
    {
	ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
	if (c >= '0' && c <= '9' )
	{
	    ++ndigit[c-'0'];
	}
	else if (c == ' ' || c == '\n' || c == '\t')
	{
	    ++nwhitespace;
	}
	else
	{
	    ++nother;
	}
    }
    printf("occurrences of digits:\n");
    for (i = 0; i < 10; ++i)
    {
	printf("%d ", ndigit[i]);
    }
    printf("\n");
    printf("number of whitespace characters: %d\n", nwhitespace);
    printf("number of other characters: %d\n", nother);
}
