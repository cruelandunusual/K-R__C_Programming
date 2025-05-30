#include <stdio.h>
#define MAXLINE 1000 //maximum input line length

int PMS_getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len; //current line length
    int max; //longest length seen so far

    char line[MAXLINE];    //current input line
    char longest[MAXLINE]; //longest line saved here

    max = 0;
    while ((len = PMS_getline(line, MAXLINE)) > 0) {
	if (len > max) { 
	    max = len;
	    copy(longest, line);
	}
    }
    if (max > 0) { //there was a line
	printf("%s", longest);
    }
    return 0;
}

/*
  Read a line into s[]; return length.
  Original array parameter is modified.
 */
int PMS_getline(char s[], int lim)
{
    char c;
    int i;
    for (i=0; i < lim-2 && ((c = getchar()) != EOF && c != '\n'); ++i) {
	s[i] = c;
    }
    if (c == '\n' || i == lim-2) {
	s[i] = '\n';
	++i;
    }
    s[i] = '\0';
    return i;
}

/*
  Copy from[] into to[]. Assume to[] is big enough.
  Original array parameter is modified.
 */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}
