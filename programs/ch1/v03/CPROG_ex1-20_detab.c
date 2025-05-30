#include <stdio.h>

#define SPACES_IN_TABS 4
#define MAXLINE 1000
#define ALPHA 0
#define BLANK   1
#define COLUMNS_IN_TAB_STOPS 80

int PMS_getline(char line[], int max_len);
void copy(char from[], char to[]);
void replace_chars_in_string(char line[], char search_char, char replace_char);
int find_last_alphanumeric_char(char line[]);
void replace_tabs_at_end(char line[], int pos);
int count_chars(char line[]);

main()
{
    char line[MAXLINE];
    int len;
    int last_alpha;
    int count;
    while ((len = PMS_getline(line, MAXLINE)) > 0) { /* while there's input */
	last_alpha = find_last_alphanumeric_char(line);
	if (last_alpha != -1) {	/* or should this be > -1? */
	    replace_tabs_at_end(line, last_alpha);
	}
	count = count_chars(line);
	printf("%d- %s", count, line);
    }
}

int PMS_getline(char line[], int max_len)
{
    int i, c;
    for (i = 0; i < max_len-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}

int count_chars(char line[])
{
    int i;
    i = 0;
    while (line[i] != '\0') {
	++i;
    }
    return i;
}

/*
  replace_chars_in_string: creates a temporary char array with MAXLINE elements,
  which is assumed to be sufficient for replacing tabs with spaces.
  (I wrote this as a first attempt at the solution, but closer reading of the question
  reveals the authors are probably looking for more. Interestingly though, this turned
  out to be the most difficult thing to write, even though it's not required and
  no longer used.)
*/
void replace_chars_in_string(char line[], char search_char, char replace_char)
{
    char tempstring[MAXLINE];
    
    int i;			/* for-loop index variable */
    int numtabs;		/* will be incremented by three */
    numtabs = 0;
    int spaces;			/* while-loop counter */
    
    for (i = 0; line[i] != '\0'; ++i) {
	if (line[i] == search_char) {
	    spaces = 0;
	    while (spaces < SPACES_IN_TABS) {
		tempstring[i + spaces + numtabs] = replace_char;
		++spaces;
	    }
	    numtabs += (SPACES_IN_TABS - 1);
	}
	else tempstring[i + numtabs] = line[i];
    }
    tempstring[i + numtabs] = line[i]; /* copies \0 into tempstring */

    copy(tempstring, line);
}

void replace_tabs_at_end(char line[], int pos)
{
    int i;
    i = 0;
    char tempstring[MAXLINE];
    
    while (i < pos) {
	tempstring[i] = line[i];
	++i;
    }
    for (i = pos ; i < COLUMNS_IN_TAB_STOPS; ++i) {
	tempstring[i] = ' ';
    }
    tempstring[i++] = '\n';
    tempstring[i] = '\0';
    
    copy(tempstring, line);
}

/*
  This doesn't work.
  (This whole exercise was abandoned.)
 */
int find_last_alphanumeric_char(char line[])
{
    int i;
    int last_pos = -1;
    int state = ALPHA;
    for (i = 0; line[i] != '\0'; ++i) {
	if ((line[i] == '\t' || line[i] == ' ') && state == ALPHA) {
	    state = BLANK;
	    last_pos = i;	/* last_pos will be the first blank char before null char */
	}
	else last_pos = i - 1;	/* last_pos will likely be a newline char */
    }
    return last_pos;
}
