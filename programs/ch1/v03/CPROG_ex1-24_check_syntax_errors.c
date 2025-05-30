/*
  Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
  unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
  double, escape sequences, and comments.
  (This program is hard if you do it in full generality.)
  
  Challenge: write this using only what's been introduced so far.
*/

#include <stdio.h>

#define SINGLE_QUOTE      '\''
#define DOUBLE_QUOTE      '"'
#define ASTERISK          '*'
#define CURLY_BRACE_OPEN  '{'
#define CURLY_BRACE_CLOSE '}'
#define BRACKET_OPEN      '('
#define BRACKET_CLOSE     ')'

#define COMPILE_SUCCESS "Syntax fine; proceed to compilation stage.\n"
#define ERRMSG_CURLY_BRACE "Syntax error: mismatched curly brace. Somewhere.\nDon't ask where.\n"
#define ERRMSG_BRACKET "Syntax error: mismatched bracket. Somewhere.\nDon't ask where.\n"

/* global variables (might not need this one) */
int b_got_next_char;

int chars_are_equal(char c1, char c2);


int main()
{

    int c; // current char
    
    int curly_open_counter    = 0;
    int curly_close_counter   = 0;
    int bracket_open_counter  = 0;
    int bracket_close_counter = 0;


    while ((c = getchar()) != EOF) {

	if (chars_are_equal(c, CURLY_BRACE_OPEN)) {
	    ++curly_open_counter;
	}
	else if (chars_are_equal(c, CURLY_BRACE_CLOSE)) {
	    ++curly_close_counter;
	}
	else if (chars_are_equal(c, BRACKET_OPEN)) {
	    ++bracket_open_counter;
	}
	else if (chars_are_equal(c, BRACKET_CLOSE)) {
	    ++bracket_close_counter;
	}
    }
    

    /* test section */
    if (curly_open_counter != curly_close_counter) {
	printf(ERRMSG_CURLY_BRACE);
    }
    else if (bracket_open_counter != bracket_close_counter) {
	printf(ERRMSG_BRACKET);
    }
    else printf(COMPILE_SUCCESS);
    
    return 0;
}


int chars_are_equal(char c1, char c2)
{

    return c1 == c2;
}
