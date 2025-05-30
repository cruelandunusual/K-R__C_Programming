#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
    int x, bits;
    x = 1302;
    bits = getbits(x, 4, 3);
    printf("%d\n", bits);
    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}


/*
x = number;
p = position;
n = number;
[xxx] = bits we are extracting;
(xxx) = bits that disappeared and aren't used anymore;

We'll assume that int is 4 bytes - 32-bit system.

if x = 5, p = 3 and n = 2
 then
return (5 >> (3 + 1 - 2) & ~(~0 << 2);
       (5 >> 2) & ~(~0 << 2);
        0001 & 0011;
        1;



We're right shifting, since we are discarding the bits, that are right of the bits,that we're
extracting.

We need to right shift since we're going to compare least significant bits
of this number,
to the least significant bits of the bit-mask.

Bit-mask will have bit positions
that we're extracting activated and those that we aren't extracting deactivated.

2 >> 00000000 00000000 00000000 0000[01]01
00000000 00000000 00000000 000000[01](01) - 2 bits discarded,that is bits that we won't compare
to bit-mask.


Then we perform NOT operation on 0(the bit-mask):
00000000 00000000 00000000 000000[00]
It switches to(the bit-mask):
11111111 11111111 11111111 111111[11]

We need this, so we could later on fill this with zeros, the zeros will be number of bits that we're extracting.
Later on bits that are zeros will be activated and bits that are ones deactivated.

11111111 11111111 11111111 111111[11] << 2
We are comparing least significant bits of the number so we left shift the zeros in this value.

(11)11111111 11111111 11111111 111111[00] - 2 bits discarded,that is bits on the left that we aren't using.

We use NOT operator on bit-mask  again
(00)00000000 00000000 00000000 000000[11] - bits are switched again,that is zeros for bits that we aren't extracting
and ones for bits we are extracting.

Why zeros for bits that we aren't extracting? Because if we AND 0 with 1 we get 0 anyway.
This is because:
1 & 0 = 0;
0 & 0 = 0;

Finally we AND the bits
00000000 00000000 00000000 000000[01]
&
00000000 00000000 00000000 000000[11]
=
00000000 00000000 00000000 000000[01]
Since we are extracting only 2 bits, they are the only ones activated in bit-mask,
all others are deactivated.

So the final result is 0001 = 1, we extracted the exact bits we needed.
*/

