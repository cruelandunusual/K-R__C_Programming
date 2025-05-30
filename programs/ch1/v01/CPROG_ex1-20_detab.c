#include <stdio.h>

#define TABS 16 // number of spaces in a tab

int PMS_getline(char s[], const int MAXLEN);
void detab(char s[], int len);

main()
{
    const int MAXLEN = 1000;
    char line[MAXLEN];
    int len;
    while ((len = PMS_getline(line, MAXLEN)) > 0) //only print if there is input
    {
	detab(line, len);
	printf("%s\n", line);
    }
    return 0;
}

/*
  Basic version of PMS_getline.
  Doesn't swap tabs for spaces.
*/
int PMS_getline(char line[], const int MAXLINE)
{
    int i;
    char c;
    
    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	line[i] = c;
    }

    if (c == '\n')
    {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}

void detab(char s[], int len)
{
    int i, tabs;
    tabs = 0;
    for (i = 0; i < len-1; ++i)
    {
	if (s[i] == '\t')
	{
	    ++tabs;//only number of tabs in s[] stored, not location
	}
    }

    char new_s[len + (tabs * (TABS-1))];
    int j = 0;
    for (i = 0; i < len-1; ++i)
    {
	if (s[i] == '\t')
	{
	    int spaces = 0;
	    while (spaces < TABS)
	    {
		new_s[(i+j) + spaces] = '*';
		++spaces;
	    }
	    j += (TABS-1);
	}
	else
	{
	    new_s[i+j] = s[i];
	}
    }
    new_s[i+j] = '\0';
    i = 0;
    //copy new_s[] into s[] so function modifies s[] without returning it
    while ((s[i] = new_s[i]) != '\0')
    {
	++i;
    }

}
