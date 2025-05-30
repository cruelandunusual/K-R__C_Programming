#include <stdio.h>

int is_power(int x);

int main(void)
{

    unsigned int answer = 0;
    unsigned int number = 127;
    unsigned int power;
    for (power = 0; power < 32; power++) {
	number & (1 << power) ? answer++ : answer;
        /*
        increment answer every time we're adding two 1s,
	otherwise do nothing.
	at the end, if answer is greater than 1 then we've added more than one pair of 1s,
	so the number we're testing isn't a power of 2.
	*/
    }

    if (answer > 1) {
	printf("%d is not a power of 2\n", number);
    }
    else { printf("%d is a power of 2\n", number); }


    printf("%d\n", is_power(128));

    /*
      testing operator order of preference
    int p = 4;
    int n = 3;
    printf("%d + 1 - %d = %d\n", p, n, (p + 1 - n));
    */
}

/*
  Alex Allain's method
*/
int is_power(int x)
{
    return !((x - 1) & x);
}
