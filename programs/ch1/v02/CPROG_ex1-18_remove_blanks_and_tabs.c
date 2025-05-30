#include <stdio.h>

int PMS_getline(char s[], int lim); /* as well as filling char s[] it returns its length */
void copy(char from[], char to[]);

main() {

    int MAXLEN = 1000;
    char line[MAXLEN];
    int len = 0;
    while ((len = PMS_getline(line, MAXLEN)) > 0) {
	// there was input
	if (len == 1) {
	    printf("input was a single newline char:\n%s", line); //do nothing
	}
	
	else if (len > 1) {
	    printf("the input was:\n%s", line);    //not sure what to do here
	}
    }
    
}

int PMS_getline(char s[], int lim) {
    
    char c;
    char prevc;
    int i;
    int spaces = 0;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	if (c == ' ' || c == '\t') {
	    ++spaces;
	    prevc = c;
	}
	else if (c != '\n') {
	    while (spaces > 0) {
		s[i-spaces] = '*';
		--spaces;
	    }
	    s[i] = c;
	    prevc = c;
	}
    }
    if (c == '\n' && prevc == ' ') {
	s[i-spaces] = c;
	
    }
    else if (c == '\n') {
	s[i-spaces] = c;
    }
    ++i;
    s[i-spaces] = '\0';
    return i-spaces;

}
