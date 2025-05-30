#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main()
{

    char my_num_string[] = "-153759";
    printf("mynum as string: %s\n", my_num_string);
    int my_num_int = atoi(my_num_string);
    printf("mynum as integer: %d\n", my_num_int);
    return 0;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
	;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
	i++;
    for (n = 0; isdigit(s[i]); i++)
	n = 10 * n + (s[i] - '0');
    return sign * n;
}
