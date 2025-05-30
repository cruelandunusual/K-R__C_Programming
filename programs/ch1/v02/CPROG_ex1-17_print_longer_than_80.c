#include <stdio.h>
#define MAXLINE 1000 //maximum input line length

int PMS_getline(char line[], int maxline);

main()
{
    int len; //current line length
    int max; //longest length seen so far

    char line[MAXLINE];    //current input line

    max = 20;
    while ((len = PMS_getline(line, MAXLINE)) > 0) { //program keeps running as long as input > 0
	if (len > max) { // but only prints input longer than max
	    printf("%s", line);
	}
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
