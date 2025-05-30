/*
  Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
  variables, both signed and unsigned, by printing appropriate values from standard headers
  and by direct computation. Harder if you compute them: determine the ranges of the various
  floating-point types.

  Notes: I obviously haven't completed this exercise, but what's not obvious is that I
  did a lot more work than is shown here; I've deleted a lot of code that demonstrated
  the various upper end and lower end values, and what happened to them when they were
  set out of bounds, etc. I mostly concentrated on unsigned long ints, although I did
  a few things with signed ints which I've now deleted.
  Basically I've left the exercise having shown that the upper limit of an unsigned long int
  is 2^64 - 1, and that the upper limit will reset to zero when its bounds are exceeded.
  I've done this in two stages:
  1 -- I've set an unsigned long int to the maximum value allowed in limits.h
  and shown that it divides by 2 64 times (actually 63, but I force an extra division by
  dividing 1 by 2), i.e. 2^64, which is equal to the value of __WORDSIZE.
  2 -- I've customised the power() function in an entirely useless way to return the maximum
  value allowed for an unsigned long if it detects that the pow value passed to it is the same
  as the machine's word size (obtained with __WORDSIZE). Then when the value is returned
  back to main() I add 1 to it two times and print the output at each step.
------------------------
  Output on my machine looks like:
  $ ./CPROG_ex2-1_determine_ranges 
  __WORDSIZE = 64
  my_unsigned_long_int = 18446744073709551615
  my_unsigned_long_int is 2^64 - 1

  value returned by power function when it detects pow is 64: 18446744073709551615
  value of my_unsigned_long_int after adding 1: 0
------------------------
  
  During the completion of this exercise I became interested in understanding more about
  different number systems and machine architecture, and so from this point onwards in
  my studies I might integrate a few more exercises which test my understanding of these
  topics.

*/

#include <stdio.h>
#include <limits.h>

unsigned long int power(int base, int n);

int main()
{
    
    /* machine word size */
    printf("__WORDSIZE = %d\n", __WORDSIZE);
    
    unsigned long my_unsigned_long_int = ULONG_MAX; // 18446744073709551615UL
    printf("my_unsigned_long_int = %lu\n", my_unsigned_long_int);

    int pow = 0;
    while (my_unsigned_long_int >= 1) {
    	my_unsigned_long_int = my_unsigned_long_int / 2;
    	++pow;
    }
    printf("my_unsigned_long_int is 2^%d - 1\n\n", pow);
    /*
      my_unsigned_long_int will exit this while-loop with a value of zero;
      pow will have been increased to the correct value of the
      range of values when counted from zero, not the maximum value itself;
      e.g. a maximum value of 255 would have a range of values of 0-255,
      i.e. 256 values, which would be denoted by 2^8.
    */

    int base = 2;
    pow = __WORDSIZE;
    my_unsigned_long_int = power(base, pow);

    printf("value returned by power function when it detects pow is %d: %lu\n", __WORDSIZE, my_unsigned_long_int);
    my_unsigned_long_int += 1;
    printf("value of my_unsigned_long_int after adding 1: %lu\n", my_unsigned_long_int);
    return 0;
}

unsigned long int power(int base, int n)
{

    unsigned long int p;
    int stop;
    if (n == __WORDSIZE) stop = 1;
    else stop = 0;
    for (p = 1; n > stop; --n) {
	p = p * base;
    }
    if (n == 1) { // then p has value 9223372036854775808
	p = p + (p - 1);
	// now p has value 18446744073709551615
    }
    return p;
}



    
