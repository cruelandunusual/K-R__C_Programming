#include <stdio.h>

int PMS_getline(char s[], const int MAXLEN);

main()
{
    const int MAXLEN = 1000;
    char line[MAXLEN];
    int len;
    while ((len = PMS_getline(line, MAXLEN)) > 0) //only print if there is input
    {
	printf("%s\n", line);
    }
    return 0;
}


/*
  // Advanced version of PMS_getline.
  // Swaps tabs for spaces.
  */  
int PMS_getline(char line[], const int MAXLEN)
{
    int i;
    char c;
    const int TABSPACE = 4;

    for (i = 0; i < MAXLEN-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	if (c == '\t')
	{
	    int j = 0;
	    while (j < TABSPACE) {
		line[i+j] = '*';
		++j;
	    }
	    i += j; // skip i forward by the number of spaces in a tab
	    --i; // but subtract 1 because the for-loop will increment i after this
	    j = 0;
	}
	else {
	    line[i] = c;
	}
    }
    
    if (c == '\n')
    {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}
