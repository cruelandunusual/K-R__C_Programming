#include <stdio.h>

#define SET_ON 1
#define MASK 1

int main(void)
{

    /* int x = 8; */
    /* printf("x = %d\n", x); */
    /* printf("SET_ON = %d\n", SET_ON); */
    /* x = x ^ SET_ON; */
    /* printf("x = x | SET_ON\n"); */
    /* printf("x = %d\n", x); */


    /* int x = 9; */
    /* printf("x = %d\n", x); */
    /* printf("MASK = %d\n", MASK); */
    /* x = x & MASK; */
    /* printf("x = x & MASK\n"); */
    /* printf("x = %d\n", x); */


    int x = 1;
    printf("x = %d\n", x);
    x = ~x;
    printf("x = ~x\n");
    printf("x = %d\n", x);
    
}
