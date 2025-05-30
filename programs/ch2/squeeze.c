#include <stdio.h>

void squeeze(char s[], char c);

int main(void)
{
    
    char string1[] = "hello";
    char s = 'l';
    printf("before squeeze()\n");
    printf("%s\n", string1);
    printf("%c\n", s);
    squeeze(string1, s);
    printf("after squeeze()\n");
    printf("%s\n", string1);
    printf("%c\n", s);

}

void squeeze(char s[], char c)
{
    
    int i, j;
    for (i = j = 0; s[i] != '\0'; ++i) {
	if (s[i] != c) {
	    s[j++] = s[i];
	}
    }
    s[j] = '\0';
}
