#include <stdio.h>

void detab(char s[], const int SPACES);
int PMS_getline(char s[], const int MAXLEN);
const int MAXLEN = 1000;

main()
{
    char line[MAXLEN];
    int len;
    while ((len = PMS_getline(line, MAXLEN)) > 0) //only print if there is input
    {
	detab(line, 4);
	printf("%s\n", line);
    }

    return 0;
}

int PMS_getline(char s[], const int MAXLEN)
{
    char c;
    int i;
    for (i = 0; i < MAXLEN-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	s[i] = c;
    }
    if (c == '\n')
    {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[], const int SPACES)
{
    char notabs[MAXLEN];
    int len = 0;
    while (s[len] != '\0')
    {
	++len;
    }
    
    int i, counter;
    for (i = 0, counter = 0; i < len; ++i, ++counter)
    {
	if (s[i] == '\t')
	{
	    int j = 0;
	    while (j < SPACES)
	    {
		notabs[counter+j] = '*';
		++j;
	    }
	    counter += j;
	    --counter;//decrement by 1 because for-loop will add 1 before next step
	    j = 0;
	}
	else
	{
	    notabs[counter] = s[i];
	}
    }
    notabs[counter] = '\0';

    len = 0;
    //copy notabs[] into s[] so function modifies s[] without returning it
    while ((s[len] = notabs[len]) != '\0')
    {
	++len;
    }
}
