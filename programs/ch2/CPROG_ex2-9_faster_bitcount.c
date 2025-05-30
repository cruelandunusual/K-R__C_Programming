/*
  Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
  in x. Explain why. Use this observation to write a faster version of bitcount.
*/

#include <stdio.h>

#define UNSIGNED_INT_SIZE_32 32

int bitcount(unsigned x);
int faster_bitcount(unsigned x);


int main()
{

    unsigned int x = 13;
    int count = 0;
    //count = bitcount(x);
    count = faster_bitcount(x);
    printf("the number of 1 bits in x = %u\n", count);
    return 0;
}


/* K&R bitcount */
int bitcount(unsigned x)
{

    int b;
    for (b = 0; x != 0; x >>= 1) {
	if (x & 01) {
	    b++;
	}
    }
    return b;
}


/* my faster version of bitcount using while loop */
/* int faster_bitcount(unsigned x) */
/* { */

/*     int b = 0; */
/*     while (x) { */
/* 	x &= (x-1); */
/* 	b++; */
/*     } */
/*     return b; */    
/* } */


/* my faster version of bitcount using for loop */
int faster_bitcount(unsigned x)
{

    int b;
    for (b = 0; x; b++) {
	x &= (x-1);
    }
    return b;    
}
