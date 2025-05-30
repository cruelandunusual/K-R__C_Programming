#include <stdio.h>

/*
  Exercise 1-16. Revise the main routine of the longest-line program so it will correctly
  print the length of arbitrary long input lines, and as much as possible of the text.
*/

#define MAXLINE 1000

int PMS_getline(char line[], int max_len);
void copy_line(char to[], char from[]);

int main()
{
    int curr_len, longest_len;
    curr_len = longest_len = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while ((curr_len = PMS_getline(line, MAXLINE)) > 0) {
	if (curr_len > longest_len) {
	    longest_len = curr_len;
	    copy_line(longest, line);
	}
    }
    /* original code: displays length of string as returned by PMS_getline */
    printf("%d, %s\n", longest_len, longest);

    return 0;    
}

int PMS_getline(char line[], int max_len)
{
    int c;
    int numchars;
    numchars = 0;
    
    while (numchars < max_len - 1 && (c = getchar()) != EOF && c != '\n') {
	line[numchars] = c;
	++numchars;
    }
    if (c == '\n') {
	line[numchars] = '\n';
	++numchars;
    }
    line[numchars] = '\0';
    return numchars;
}

void copy_line(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}
