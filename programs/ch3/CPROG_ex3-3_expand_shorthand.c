/*
  Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
  the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
  and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
  leading or trailing - is taken literally.
 */

#include <stdio.h>
#include "util/pmsutils.h"
#include <ctype.h>

#define MAXLINE 1000

int main()
{

    //char line[MAXLINE];
    //char line_esc[MAXLINE];

    for (int i = 'a'; i <= 'z'; i++) {
	printf("%c", i);
    }
    
    return 0;
}
