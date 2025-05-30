#include <stdio.h>

/*
  Exercise 1-9. Write a program to copy its input to its output,
  replacing each string of one or more blanks by a single blank.
 */

/*
  Whilst reviewing some of my earlier material I thought I'd have
  a go at re-writing this. I have to confess it was a little tricky,
  but that was the whole point of trying it. The main thing worth
  noting is that I solved it in what I think is a much more intuitive
  way, whereas my v1 solution used state variables. I seem to remember
  I didn't come up with that idea on my own. However, I genuinely
  don't think that solution is particularly clear. Perhaps it would
  hold up better against more complicated states and conditions.
 */

int main()
{
    int c, prevc;
    prevc = c = 0;
    while ( (c = getchar()) != EOF) {
	if (c == ' ' && prevc != c) {
	    putchar(c);
	}
	else if (c != ' ') {
	    putchar(c);
	}
	prevc = c;
    }
}
