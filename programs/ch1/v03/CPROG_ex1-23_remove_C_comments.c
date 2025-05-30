/*
  Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
  handle quoted strings and character constants properly. C comments don't nest.

  Challenge: write this using only what's been introduced so far.
*/

#include <stdio.h>

#define SINGLE_QUOTE  '\''
#define DOUBLE_QUOTE  '"'
#define ASTERISK      '*' // watch out for this character constant...
#define FORWARD_SLASH '/' // and this one...

/*
  test comment
*/

int chars_are_equal(char c1, char c2);
int get_next_token();

// names prefaced with b_ are boolean
int b_got_next_char = 0;
int b_do_print = 0;
int b_comment_closed = 0;


int main()
{

    int c, nextc;

    while ((c = getchar()) != EOF) {

	/*
	  test the current char against
	  the comment-opening char: FORWARD_SLASH
	*/
	if (chars_are_equal(c, FORWARD_SLASH)) {
	    // get the next char to test against ASTERISK
	    nextc = get_next_token();
	    if (chars_are_equal(nextc, ASTERISK)) {
		// we're in a comment, stop printing
		b_do_print = 0;
	    }
	    else {
		// non comment-related FORWARD_SLASH, keep printing
		b_do_print = 1;
	    }
	    
	}

	/*
	  test the current char against
	  the comment-closing char: ASTERISK
	*/
	if (chars_are_equal(c, ASTERISK)) {
	    // get the next char to test against FORWARD_SLASH
	    nextc = get_next_token();
	    if (chars_are_equal(nextc, FORWARD_SLASH)) {
		b_comment_closed = 1; // comment closed
		b_do_print = 1;       // so start printing
		c = getchar();        // get the next char after FORWARD_SLASH for printing
	    }
	    else {
		// non comment-related asterisk, keep printing
		b_do_print = 1;
	    }
	}

	/*
	  boolean test section:
	  test the various boolean combinations
	  to decide whether or not to print
	*/
	if (b_do_print) {
	    if (b_comment_closed) {
		// a comment was just closed
		putchar(c);
	    }
	    else if (!b_comment_closed && b_got_next_char) { // we're inside a comment
		// we tested a non comment-related asterisk, so print it
		putchar(c);
		// we grabbed nextc to test for FORWARD_SLASH;
		// test was negative, so need to print it too
		putchar(nextc);
	    }
	    else {
		// we're in non comment code
		putchar(c);
	    }
	}

	// reset the booleans to false
	b_got_next_char = 0;
	b_comment_closed = 0;
    }
    
    return 0;
}

/*
  test comment
*/

int chars_are_equal(char c1, char c2)
{

    return c1 == c2;
}

int get_next_token()
{
    b_got_next_char = 1;
    return getchar();
}
