#include <stdio.h>

#define TABS 4 // number of spaces in a tab

int PMS_getline(char s[], const int MAXLEN);
void entab(char s[], int len);

#define WORD  1
#define BLANK 0

main()
{
    const int MAXLEN = 1000;
    char line[MAXLEN];
    int len;
    while ((len = PMS_getline(line, MAXLEN)) > 0) //only print if there is input
    {
	entab(line, len);
	printf("%s\n", line);
    }
    return 0;
}

/*
  Basic version of PMS_getline.
  Doesn't swap tabs for spaces.
*/
int PMS_getline(char line[], const int MAXLEN)
{
    int i;
    char c;
    
    for (i = 0; i < MAXLEN-1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

void entab(char s[], int len)
{
    char new_s[len];
    int state = WORD;
    int spaces = 0;
    int i;
    int j = 0;
    for (i = 0; i < len-1; i++)
    {
	if (s[i] == ' ')
	{
	    state = BLANK;
	    ++spaces;
	}
	else if (state == BLANK)
	{
	    state = WORD;
	    if ((spaces / TABS) > 0)
	    {
		int temp = spaces / TABS;
		while (temp > 0)
		{
		    /*
		      do the array stuff here
		    */
		    new_s[j] = '\t';
		    temp--;
		    ++j;
		}
		spaces = spaces % TABS;
	    }
	    while (spaces > 0)
	    {
		/*
		  do the array stuff here
		*/
		new_s[j] = '!';
		--spaces;
		++j;
	    }
	    --i;//decrement i loop counter because for-loop will
	    //increment it after this else-if clause
	}
	else
	{
	    /*
	      copy the array as normal
	    */
	    printf("copying the array as normal with %d j and %d i \n", j, i);
	    new_s[j] = s[i];
	    putchar(new_s[j]);printf("\n");
	    ++j;
	}
    }
    
    new_s[j] = '\0';
    
    i = 0;
    while ((s[i] = new_s[i]) != '\0')
    {
	++i;
    }
}
