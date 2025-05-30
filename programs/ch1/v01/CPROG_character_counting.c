#include <stdio.h>

/* Write a program to print the number of characters in input */
main()
{
    long nc = 0;
    while (getchar() != EOF) {
	++nc;
    }
    printf("Number of characters in input: %ld\n", nc);	

}
