#include <stdio.h>

main()
{
    char c;
    while ((c = getchar()) != EOF) {
	if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
	    putchar(c);
	}
    }	
}
