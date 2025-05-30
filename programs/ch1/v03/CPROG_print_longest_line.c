#include <stdio.h>

#define MAXLINE 1000

int PMS_getline(char line[], int max_len);
void copy_line(char to[], char from[]);

int main()
{
    int curr_len, last_len;
    curr_len = last_len = 0;
    
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((curr_len = PMS_getline(line, MAXLINE)) > 0) {
	if (curr_len > last_len) {
	    last_len = curr_len;
	    copy_line(longest, line);
	}
    }

    printf("%s", longest);
}

int PMS_getline(char line[], int max_len)
{
    char c;
    int numchars;
    numchars = 0;
    
    while ( numchars < max_len-1 && (c = getchar()) != EOF && c != '\n' ) {
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

void copy_line(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}
