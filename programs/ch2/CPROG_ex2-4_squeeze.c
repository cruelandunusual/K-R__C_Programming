/*

Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.

*/


#include <stdio.h>

#define BOOL char
#define TRUE  1
#define FALSE 0

void squeeze(char s1[], char s2[]);

int main(void)
{
    
    char string1[] = "The quick brown fox jumps over the lazy dog.";
    char string2[] = "aeiou-bcdfghjk";
    printf("before squeeze()\n");
    printf("string1 = %s\n", string1);
    printf("string2 = %s\n", string2);
    squeeze(string1, string2);
    printf("after squeeze()\n");
    printf("string1 = %s\n", string1);

}

void squeeze(char s1[], char s2[])
{
    
    int i, j;
    BOOL b_found = FALSE;
    for (i = j = 0; s1[i] != '\0'; i++) {
	for (int x = 0; s2[x] != '\0'; x++) {
	    if (s1[i] == s2[x]) {
		b_found = TRUE;
	    }
	}
	if (b_found == FALSE) {
	    s1[j++] = s1[i];
	}
	b_found = FALSE;
    }
    s1[j] = '\0';
}
