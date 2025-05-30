#include <stdio.h>

int main()
{

    int c;
    int i;
    int n = 10;

    while ((c = getchar()) != EOF) {
	if (c != ' ' && c != '\n') {
	    putchar(c);
	}
    }

    for (i = 0; ; ++i) {
	printf("%2d\n", i);
	if (i < n) {
	    continue;
	}
	else break;
    }
    
    return 0;
}
