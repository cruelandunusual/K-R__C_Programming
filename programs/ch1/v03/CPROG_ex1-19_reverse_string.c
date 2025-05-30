#include <stdio.h>

/*
  Exercise 1-19. Write a function reverse(s) that reverses the character string s.
  Use it to write a program that reverses its input a line at a time.
*/

#define MAXLINE 1000

int PMS_getline(char line[], int max_len);
void reverse(char s[]);

main()
{
    char line[MAXLINE];
    int len;
    while ((len = PMS_getline(line, MAXLINE)) > 0) {
	/* ignore lines of length 1 as they have only newline */
	/* and lines of length 2 as they only have one char */
	if (len >= 2) {
	    reverse(line);
	}
	printf("%s", line);
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

void reverse(char s[])
{
    int len;
    len = 0;
    /* first we find the length of the string */
    while (s[len] != '\0') {
	++len;
    }
    /* s[len] now equals \0 so we subtract 1
       so \0 not swapped during reverse*/
    if (s[--len] == '\n') {
	/* subtract 1 from len if char before \0 is newline */
	/* as we want to ignore newline from reverse operation */
	--len;
    }
    
    char temp;
    if (len == 0) {
	/* don't do anything to strings with one char */
	return;
    }
    else if (len == 1) {
	/* strings with two chars don't need a loop for reversing. */
	temp = s[0];
	s[0] = s[1];
	s[1] = temp;
    }
    else {
	/* loop for any string longer than two chars. */
	int i;
	for (i = 0; i < len/2; ++i) {
	    temp = s[i];
	    s[i] = s[len-i];
	    s[len-i] = temp;
	}
    }
}
