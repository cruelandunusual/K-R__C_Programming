#include <stdio.h>

int power(int m, int n);

main()
{
    int i;
    printf("Testing power(int base, int n) function:\n");
    for (i = 0; i < 10; ++i) {
	printf("2 raised to the power %d is: %4d\n", i, power(2, i));
    }

    return 0;
}

/* power: raise base to nth power; n >= 0 */
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i) {
	p = p * base;
    }
    return p;
}
