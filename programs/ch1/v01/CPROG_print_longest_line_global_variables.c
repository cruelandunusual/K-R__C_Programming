#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int PMS_getline(void);
void copy(void);

main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = PMS_getline()) > 0) {
	if (len > max) {
	    max = len;
	    copy();
	}
    }
    if (max > 0) {
	printf("%s", longest);
    }
    return 0;
}

int PMS_getline()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i] = '\n';
	++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
	++i;
    }
}
