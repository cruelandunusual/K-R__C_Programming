#include <stdio.h>
//#define MAXLINE 1000 //maximum string length

int PMS_getline(char line[], const int MAXLINE);
void copy(char to[], char from[]);

main()
{
    const int MAXLINE = 1000;
    int currlen = 0;
    char currline[MAXLINE];
    while ((currlen = PMS_getline(currline, MAXLINE)) > 0) {
	if (currlen > 20) {
	    printf("%s", currline);
	}
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
    char c;
    int i;
    for (i=0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
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
