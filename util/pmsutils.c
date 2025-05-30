#include <stdio.h>

int PMS_getline(char line[], int max_len)
{

    int c, i;
    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';
    return i;
}

int PMS_isdash(char c)
{
    return (c == '-');
}
