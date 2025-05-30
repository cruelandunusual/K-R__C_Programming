#include <stdio.h>

/*
  
  Exercise 2-2. Write a loop equivalent to the following for-loop without using && or ||

  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
      s[i] = c;
  }
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
    printf("%d, %s\n", longest_len, longest);

    return 0;
}

int PMS_getline(char line[], int max_len)
{

    int c;
    int numchars = 0;
    
    while (numchars < max_len - 1) {
	if ((c = getchar()) != '\n') {
	    if (c != EOF) {
		line[numchars] = c;
		++numchars;
	    }
	    else {
		line[numchars] = '\0';
		return numchars;
	    }
	}
	else {
	    line[numchars++] = '\n';
	    line[numchars] = '\0';
	    return numchars;
	}
    }
	
}

void copy_line(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}
