#include <stdio.h>

int PMS_getline(char s[], const int MAXLEN);
void reverse_string(char s[], int len);
void swap_every_second_char(char s[], int len);

main()
{
    int MAXLEN = 1000;
    char line[100];
    int len = 0;
    while ((len = PMS_getline(line, MAXLEN)) > 0) // only print if there is input
    {
	printf("original array: %s\n", line);
	//reverse_string(line, len);
	swap_every_second_char(line, len);
	printf("every second char swapped: %s\n", line);
    }
}

void reverse_string(char s[], int len)
{
    int i;
    char temp;
    int end = len-2;
    for (i = 0; i < len/2; ++i)
    {
	temp = s[end-i];
	s[end-i] = s[i];
	s[i] = temp;
    }
}

void swap_every_second_char(char s[], int len)
{
    int i;
    char temp;
    int end = len-2;
    for (i = 1; i < len/2; i+=2)
    {
	/*
	  abcdefghi
	  becomes
	  ahcfedgbi
	*/
	temp = s[end-i];
	s[end-i] = s[i];
	s[i] = temp;
    }
}

int PMS_getline(char s[], const int MAXLEN)
{
    char c;
    int len = 0;
    while ((c = getchar()) != EOF && len < MAXLEN-1)
    {
	s[len] = c;
	++len;
    }
    s[len] = '\0';
    return len;
}
