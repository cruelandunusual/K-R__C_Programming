#include <stdio.h>

/*
  Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#define MAXLINE 1000

int PMS_getline(char line[], int max_len);
void copy_line(char to[], char from[]);

main()
{
    int len;
    len = 0;

    char line[MAXLINE];

    while ((len = PMS_getline(line, MAXLINE)) > 0) { /* there is input */
	if (len > 30) {
	    printf("%s\n", line);
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
