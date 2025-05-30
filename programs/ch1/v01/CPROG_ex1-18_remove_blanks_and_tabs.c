#include <stdio.h>

int PMS_getline(char line[], int maxline);
void copy(char to[], char from[]);
void copy_blank_to_asterisk(char from[], char to[]);

main()
{
    int currlen, longestlen;
    currlen = longestlen = 0;
    const int MAXLINE = 1000;
    
    char currline[MAXLINE];
    char longestline[MAXLINE];
    char proof[MAXLINE];
    
    while ((currlen = PMS_getline(currline, MAXLINE)) > 0) {
	if (currlen > longestlen) {
	    longestlen = currlen;
	    copy(longestline, currline);
	}
    }
    if (longestlen > 0) { //there was input
	printf("longestline is %d chars long after removing trailing \
blanks and tabs.\n%s", longestlen, longestline);
	copy_blank_to_asterisk(longestline, proof);
	printf("\nproof:\n%s\n", proof);
    }
    return 0;
}

/*
  Stores input in array line[].
  Returns length of array.
  Original array argument is modified.
*/
int PMS_getline(char line[], const int MAXLINE)
{
    int i;
    int spaces = 0;
    char c, prevc;
    
    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	if (c == ' ' || c == '\t')
	{
	    ++spaces;
	    prevc = c;
	}
	else if (c != '\n')
	{
	    while (spaces > 0)
	    {
		line[i-spaces] = '*';
		--spaces;
	    }
	    line[i] = c;
	    prevc = c;
	}
    }

    if (c == '\n' && prevc == ' ')
    {
	line[i-spaces] = c;
	++i;
    }
    line[i-spaces] = '\0';
    return (i-spaces)-1;
}

/*
  Copies char from[] into char to[].
  Assumes to[] is long enough.
  Original array argument to[] is modified.
*/
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}

/*
  Copies char from[] into char to[],
  replacing spaces and tabs with asterisk.
  Assumes to[] is long enough.
  Original array argument to[] is modified.
*/
void copy_blank_to_asterisk(char from[], char to[])
{
    int i = 0;
    while (from[i] != '\0')
    {
	to[i] = (from[i] == ' ') ? '*' : from[i];
	++i;
    }
    to[i] = '\0';
}
