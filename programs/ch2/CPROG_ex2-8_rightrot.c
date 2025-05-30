/*
  Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
  to the right by n positions.
*/

#include <stdio.h>

#define UNSIGNED_INT_SIZE_32 32

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main()
{

    unsigned int x, x_rot;
    int n;
    x = 2;
    n = 1;
    x_rot = rightrot(x, n);
    printf("x before rightrot = %u\n", x);
    
    printf("x after rightrot by %d = %u\n", n, x_rot);
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


unsigned rightrot(unsigned x, int n)
{
    
    unsigned stored_bits = ~(~0 << n); //create a mask of n 1s at rightmost end
    stored_bits &= x; //ANDing with x stores the relevant bits of x in the mask bits of stored_bits
    x >>= n; //shift x n times
    stored_bits <<= UNSIGNED_INT_SIZE_32 - n; //shift the mask bits to the leftmost end of stored_bits
    return x ^ stored_bits; //XORing puts the relevant bits of stored_bits back into x
}
