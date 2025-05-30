#include <stdio.h>

#define MAXLEN 100

int PMS_strlen(const char* buf);

int main()
{
    int i, my_string_length;
    char my_string[MAXLEN + 1];
    for (i = 0; i < MAXLEN; ++i) {
	my_string[i] = 'a';
    }
    my_string[i] = '\0';

    my_string_length = PMS_strlen(my_string);
    printf("%d\n", my_string_length);

    my_string[16] = '\0';
    my_string_length = PMS_strlen(my_string);
    printf("%d\n", my_string_length);
    
    return 0;
}
	
int PMS_strlen(const char buf[])
{
    int i = 0;
    while (buf[i] != '\0') {
	++i;
    }
    return i;
}
