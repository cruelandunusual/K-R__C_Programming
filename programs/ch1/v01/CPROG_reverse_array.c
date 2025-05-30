#include <stdio.h>

int PMS_getline(char s[], const int MAXLEN);
void reverse_string(char s[], int len);

main()
{
    const int MAXLEN = 1000;
    char line[MAXLEN];
    int len;
    while ((len = PMS_getline(line, 1000)) > 0) // only print if there is input
    {
	reverse_string(line, len);
	printf("%s\n", line);
    }
    return 0;
}

int PMS_getline(char s[], const int MAXLEN)
{
    int i;
    char c;
    for (i = 0; i < MAXLEN-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
	s[i] = c;
    }
    if (c == '\n')
    {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

void reverse_string(char s[], int len)
{
    int i, j;
    char temp;
    for (i = 0, j = len-1; i < len/2; ++i, --j)
    {
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
    }
}
