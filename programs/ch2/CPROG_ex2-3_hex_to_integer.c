/*
  Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
  (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
  through 9, a through f, and A through F.
*/

#include <stdio.h>

#define MAX 8

int htoi(char *hex);

int main()
{

    //fill hex array here with meaningful hex values
    char hex[MAX];
    hex[0] = '0';
    hex[1] = 'x';
    hex[2] = 'f';
    hex[3] = '2';
    hex[4] = '3';
    hex[5] = 'a';
    hex[6] = '\0';

/*
    hex[0] = '1';
    hex[1] = '2';
    hex[2] = 'B';
    hex[3] = '4';
    hex[4] = '\0';
*/

    printf("hexadecimal value: %s\n", hex);
    int decimal = htoi(hex);
    printf("decimal value: %d\n", decimal);
    printf("hexadecimal value: %x\n", decimal);

    return 0;
}


int htoi(char hex[])
{

    int ans = 0;
    int i = 0;
    int hex_start = 0;
    
    if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] == 'X')) {
	hex_start = 2;
    }

    for (i = hex_start; hex[i] != '\0'; ++i) {
	int temp = 0; //faster to store values in a temp variable on same stack as the loop
	if (hex[i] >= '0' && hex[i] <= '9') {
	    temp = hex[i] - '0';
	}
	else if (hex[i] >= 'A' && hex[i] <= 'F') {
	    temp = hex[i] - 'A' + 0xA;
	}
	else if (hex[i] >= 'a' && hex[i] <= 'f') {
	    temp = hex[i] - 'a' + 0xA;
	}
	if (i == hex_start) ans = temp;
	else ans = (ans * 16) + temp;
    }
    return ans;
}


/*
int htoi(char hex[])
{

    int ans = 0;
    int i = 0;
    int hex_stop = 0;
    
    if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] == 'X')) {
	hex_stop = 2;
    }
    while (hex[i] != '\0') {//find end of char array
	++i;
    }

    int hex_base;
    for (i -= 1, hex_base = 1; i >= hex_stop; --i, hex_base *= 16) {
	int temp = 0; //faster to store values in a temp variable on same stack as the loop
	if (hex[i] >= '0' && hex[i] <= '9') {
	    temp = hex[i] - '0';
	}
	else if (hex[i] >= 'A' && hex[i] <= 'F') {
	    temp = hex[i] - 'A' + 10;
	}
	else if (hex[i] >= 'a' && hex[i] <= 'f') {
	    temp = hex[i] - 'a' + 10;
	}

	ans += temp * hex_base;
    }
    return ans;
}
*/
