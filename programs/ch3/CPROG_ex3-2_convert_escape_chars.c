/*
  Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
  visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
  function for the other direction as well, converting escape sequences into the real characters.
 */

#include <stdio.h>
#include "../util/pmsutils.h"

#define MAXLINE 1000

void escape(char s[], char t[]);
void reverse_escape(char t[], char s[]);


int main()
{

    char line[MAXLINE];
    char line_esc[MAXLINE];
    int len = 0;
    
    while ((len = PMS_getline(line, MAXLINE)) > 0) { /* there is input */
	printf("%s\n", line); // print the original line
	escape(line, line_esc);
	printf("%s\n", line_esc); // print the line with escape chars removed
	reverse_escape(line, line_esc);
	printf("%s\n", line); // print the line with escape chars replaced
    }


    return 0;
}


/*
  reverse_escape: copies s[] to t[], reversing the effects of escape() by
  replacing '\' 'n' with single escape chars, etc, making them normal
  escape characters.
  Uses two switch statements, one nested inside the other.
 */
void reverse_escape(char t[], char s[])
{

    int i, j;
    i = j = 0;
    
    while (s[i] != '\0') {
	switch (s[i]) {
	case '\\':
	    switch (s[++i]) {
	    case '-':
		t[j] = ' ';
		break;
	    case 'n':
		t[j] = '\n';
		break;
	    case 't':
		t[j] = '\t';
		break;
	    default:
		break;
	    }
	    break;
	default:
	    t[j] = s[i];
	    break;
	}
	i++;
	j++;
    }
    t[j] = s[i]; // copy '/0' to t[];
    
}



/*
  reverse_escape: copies s[] to t[], reversing the effects of escape() by
  replacing '\' 'n' with single escape chars, etc, making them normal
  escape characters.
  Uses a switch statement.
 */
/* void reverse_escape(char t[], char s[]) */
/* { */

/*     int i, j; */
/*     i = j = 0; */
    
/*     while (s[i] != '\0') { */
/* 	if (s[i] == '\\') { */
/* 	    switch (s[++i]) { */
/* 	    case '-': */
/* 		t[j] = ' '; */
/* 		break; */
/* 	    case 'n': */
/* 		t[j] = '\n'; */
/* 		break; */
/* 	    case 't': */
/* 		t[j] = '\t'; */
/* 		break; */
/* 	    default: */
/* 		break; */
/* 	    } */
/* 	} */
/* 	else { */
/* 	    t[j] = s[i]; */
/* 	} */
/* 	i++; */
/* 	j++; */
/*     } */
/*     t[j] = s[i]; // copy '/0' to t[]; */
    
/* } */


/*
  escape: copies t[] to s[], replacing single escape chars
  with '\' 'n', etc, making them visible in an unambiguous way.
  Uses a switch statement.
 */
void escape(char t[], char s[])
{

    int i, j;
    i = j = 0;
    
    while (t[i] != '\0') {
	switch (t[i]) {
	case ' ':
	    s[j] = '\\';  // the single backslash itself needs to be 'escaped'
	    s[++j] = '-'; // add backslash dash for every space
	    break;
	case '\n':
	    s[j] = '\\';
	    s[++j] = 'n'; // add backslash n for every newline
	    break;
	case '\t':
	    s[j] = '\\';
	    s[++j] = 't'; // backslash t for every tab
	    break;
	default:
	    s[j] = t[i]; // default case copies the rest of t[] to s[] as normal
	    break;
	}
	i++;
	j++;
    }
    s[j] = t[i]; // copy '\0' to s[];
    
}
