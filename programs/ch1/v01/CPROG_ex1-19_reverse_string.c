#include <stdio.h>

void reverse(char s[]);
int PMS_getline(char line[], const int MAXLINE);
int string_length(char s[]);

main()
{
    char line[64];
    char c;
    int len;
    while ((len = PMS_getline(line, 64)) > 0)
    {
	reverse(line);
	printf("%s\n", line);
    }
    return 0;
}
/*
void reverse(char s[])
{
    int len = string_length(s);
    char reversed[len];
    int i = 0;
    --len;
    while (len >= 0) {
	reversed[i] = s[len];
	--len;
	++i;
    }
    reversed[i] = '\0';
    i = 0;
    while ((s[i] = reversed[i]) != '\0') {
	++i;
    }
}
*/
void reverse(char s[])
{
    int len = string_length(s);
    int i, j;
    char temp;
    for (i=0, j=len-1; i<len/2; ++i, --j)
    {
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
    }
}

int string_length(char s[])
{
    int length = 0;
    while (s[length] != '\0')
    {
	++length;
    }
    return length;
}

int PMS_getline(char line[], const int MAXLINE)
{
    int i;
    char c;
    
    for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	line[i] = c;
    }

    if (c == '\n')
    {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}
