/*
  Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
  position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    
    int x, y, bits;
    x = 0xFFFFFFFF;
    y = 0xFFFFFFF0;
    int p, n;
    p = 7;
    n = 4;
    printf("x = %x\ny = %x\n", x, y);
    bits = setbits(x, p, n, y);
    printf("after setbits(%x, %d, %d, %x) x = %x\n", x, p, n, y, bits);
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
    unsigned mask = ~(~0 << n) << p - (n - 1); //create a mask of n 1s to bitwise AND with the intermediate result
    y &= mask; //y now has all bits set to zero, except for the n bits we're interested in
    return x ^ y; //XORing again sets the n bits of x to same as y, leaving rest of x unaffected
}
