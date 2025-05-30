/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
 */

#include <stdio.h>


int any(char s1[], char s2[]);

int main(void)
{
    
    char string1[] = "The quick brown fox jumps over the lazy dog.";
    char string2[] = "zy";
    printf("before squeeze()\n");
    printf("string1 = %s\n", string1);
    printf("string2 = %s\n", string2);
    signed int location = any(string1, string2);
    if (location >= 0) {
    printf("the first location in '%s' of any char in '%s' is %d.\n", string1, string2, location);
    }
    else printf("No characters from '%s' were found in '%s'.\n", string2, string1);

}

int any(char s1[], char s2[])
{
    
    int i;
    for (i = 0; s1[i] != '\0'; i++) {
	for (int x = 0; s2[x] != '\0'; x++) {
	    if (s1[i] == s2[x]) {
		return i;
	    }
	}
    }
    return -1;
}
