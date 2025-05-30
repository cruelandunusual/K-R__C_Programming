/*
  Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
  with a conditional expression instead of if-else.
*/

#include <stdio.h>

int lower(int c);
int PMS_lower(int c);


int main()
{

    char line[1000] = "Here'S a LiNe to tESt my PRograM wIth";
    printf("line without calling PMS_lower() : %s\n", line);
    printf("line after calling PMS_lower()   : ");
    for (int i = 0; line[i] != '\0'; ++i) {
	putchar(PMS_lower(line[i]));
    }
    printf("\n");
    return 0;
}


/* K&R lower */
int lower(int c)
{

    if (c >= 'A' && c <= 'Z') {
	return c + 'a' - 'A';
    }
    else {
	return c;
    }	    
}


/* PMS_lower */
int PMS_lower(int c)
{

    (c >= 'A' && c <= 'Z') ? c += 'a' - 'A' : c;
    return c;
}
