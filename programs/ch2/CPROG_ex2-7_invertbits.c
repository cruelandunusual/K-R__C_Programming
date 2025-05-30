/*
  Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
  position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main()
{

    unsigned int x, bits;
    x = 2743;
    printf("x = %d\n", x);
    bits = invert(x, 7, 4);
    printf("%d\n", bits);
    printf("%x\n", bits);
    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    
    return (x >> (p+1-n)) & ~(~0 << n);
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{

    y <<= p - (n - 1); //shift the n bits we're interested in to position p
    y ^= x; //XOR once and store result in y
    unsigned mask = ~(~0 << n) << p - (n - 1); //create a mask of n 1s at position p to BITWISE AND with the intermediate result
    y &= mask; //y now has all bits set to zero, except for the n bits we're interested in
    return x ^ y; //XORing again sets the n bits of x to same as y, leaving rest of x unaffected
}


unsigned invert(unsigned x, int p, int n)
{
    
    unsigned mask = ~(~0 << n) << p - (n - 1); //create a mask of n 1s at position p
    return x ^ mask; //XORing flips the mask bits but leaves the rest unaffected
}
