/*
  Self-assigned exercise: write a program to convert
  base 10 numbers to their binary equivalents.
*/

#include <stdio.h>

void decimal_to_binary(char *binary, int decimal);

int main()
{
    char binary[17];
    int number;
    do {
	printf("Enter a number (max allowed is 65535):\n");
	scanf("%d", &number);
	decimal_to_binary(binary, number);
	printf("%d is %s in binary\n", number, binary);
    }
    while (number != 0);

    return 0;
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
