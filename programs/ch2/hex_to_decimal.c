/*
  Self-assigned exercise: write a program to convert
  decimal numbers to their binary equivalents.
*/

#include <stdio.h>

#define MAX 8
#define HEX 16

int htoi(char *hex);
void decimal_to_binary(char *binary, int decimal);

int main()
{

    //fill hex array here with meaningful hex values
    char hex[MAX];
    hex[0] = '0';
    hex[1] = 'x';
    hex[2] = 'f';
    hex[3] = 'a';
    hex[4] = '2';
    hex[5] = '\0';

/*
    hex[0] = '1';
    hex[1] = '2';
    hex[2] = '3';
    hex[3] = '4';
    hex[4] = '\0';
*/


/*
    hex[0] = '8';
    hex[1] = '0';
    hex[2] = '0';
    hex[3] = '0';
    hex[4] = '0';
    hex[5] = '0';
    hex[6] = '0';
    hex[7] = '0';
    hex[8] = '\0';

*/
    
    printf("hexadecimal value: %s\n", hex);
    int decimal = htoi(hex);
    printf("decimal value: %u\n", decimal); // %u prints unsigned ints

/*
    char binary[17];
    int number;
    do {
	printf("Enter a hex number ():\n");
	scanf("%d", &number);
	decimal_to_binary(binary, number);
	printf("%d is %s in binary\n", number, binary);
    }
    while (number != 0);
    */
    return 0;
}

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

void decimal_to_binary(char *binary, int decimal)
{
    int i;
    for (i = 0; i < 16; ++i) {
	binary[i] = '0';
    }
    binary[i] = '\0'; //i is now 16 and indexes last element

    char bit;
    for (i = 15; decimal > 0; decimal /= 2, --i) {
	if (decimal % 2 == 1) { bit = '1'; }
	else { bit = '0'; }
	binary[i] = bit;
    }
}
