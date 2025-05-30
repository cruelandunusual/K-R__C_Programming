#include <stdio.h>

void XOR_flip(int *a, int *b);

int main()
{

    int a = 67;
    int b = 146;

    printf("before XOR_flip a = %d, b = %d\n", a, b);
    XOR_flip(&a, &b);
    
    printf("after XOR_flip a = %d, b = %d\n", a, b);
}


void XOR_flip(int *a, int *b)
{
    
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
