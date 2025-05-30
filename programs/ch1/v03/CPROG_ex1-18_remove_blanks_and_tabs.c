#include <stdio.h>

/*
  Exercise 1-18. Write a program to remove trailing blanks and tabs
  from each line of input, and to delete entirely blank lines.
*/

#define MAXLINE 1000

int PMS_getline(char line[], int max_len);
void remove_trailing_blanks(char line[], int max_len);

int main()
{
    char line[MAXLINE];
    int len;
    while ((len = PMS_getline(line, MAXLINE)) > 0) {
	/* ignore lines of length 1 as they have only newline */
	if (len > 0) {
	    remove_trailing_blanks(line, len);
	    printf("%s", line);
	}
    }
}

int PMS_getline(char line[], int max_len)
{
    int c, i;
    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';
    return i;
}

void remove_trailing_blanks(char line[], int max_len)
{
    int counter, i;
    counter = 0;
    for (i = 0; i < max_len-1; ++i) {
	if (line[i] == ' ' || line[i] == '\t') {
	    ++counter;
	}
	else counter = 0;
    }
    if (counter > 0) {
	if (line[max_len-1] == '\n') {
	    line[(max_len-1) - counter] = '\n';
	    line[((max_len-1) - counter)+1] = '\0';
        }
        else {
	    line[max_len - counter] = '\0';
	}
    }
}
