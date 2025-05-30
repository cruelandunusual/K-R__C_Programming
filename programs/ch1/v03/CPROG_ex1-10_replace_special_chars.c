#include <stdio.h>

/*
  Exercise 1-10. Write a program to copy its input to its output,
  replacing each tab by \t, each backspace by \b, and each backslash by \\.
  This makes tabs and backspaces visible in an unambiguous way.
 */

main()
{
    int c;
    int special_char = 0;
    
    char special_output[3];
    special_output[0] = '\\';
    special_output[2] = '\0';

    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    special_char = 1;
	    special_output[1] = 't';
	}
	else if (c == '\b') {
	    special_char = 1;
	    special_output[1] = 'b';
	}
	else if (c == '\\') {
	    special_char = 1;
	    special_output[1] = '\\';
	}
	else if (c == '\n') {
	    special_char = 1;
	    special_output[1] = 'n';
	}
	else if (c == ' ') {
	    special_char = 1;
	    special_output[1] = '#';
	}

	if (special_char) {
	    printf("%s", special_output);
	}
	else {
	    putchar(c);
	}
	special_char = 0;
    }
}
