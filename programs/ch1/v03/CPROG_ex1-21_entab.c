#include <stdio.h>

#define SPACES_IN_TABS 4
#define MAXLINE 1000
#define ALPHA 0
#define TAB   1
#define COLUMNS_IN_TAB_STOPS 80

int PMS_getline(char line[], int max_len);
void copy(char from[], char to[]);
void replace_chars_in_string(char line[], char search_char, char replace_char);
int find_last_alphanumeric_char(char line[]);
void replace_tabs_at_end(char line[], int pos);
void entab(char line[], int pos);

main()
{
    char line[MAXLINE];
    int len;
    int last_alpha;
    while ((len = PMS_getline(line, MAXLINE)) > 0) { /* while there's input */
	last_alpha = find_last_alphanumeric_char(line);
	if (last_alpha >= 0) {
	    entab(line, last_alpha);
	    printf("%s", line);
	}
	else printf("%s", line);
    }
}

/*
  PMS_getline: gets a line of text from input, stores in line[];
  returns the length of line[] as int
*/
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

/*
  copy: copies from[] to to[];
  assumes to[] is large enough
*/
void copy(char from[], char to[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}

/*
  replace_chars_in_string: creates a temporary char array with MAXLINE elements,
  which is assumed to be sufficient for replacing tabs with spaces.
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

/*
  entab: adds tabs to line[] from pos until reaches
  COLUMNS_IN_TAB_STOPS. Fills out last couple of char
  positions with blanks if necessary (e.g. if tabs alone
  will overreach COLUMNS_IN_TAB_STOPS)
  Creates a temp char array of length MAXLINE, assumes
  this will be big enough.
 */
void entab(char line[], int pos)
{
    char tempstring[MAXLINE];
    int i;
    int counter = pos;

    for (i = 0; i < pos; ++i) {
	tempstring[i] = line[i];
    }

    i = pos;
    
    while (counter < COLUMNS_IN_TAB_STOPS) {
	tempstring[i] = '\t';
	counter += SPACES_IN_TABS;
	++i;
    }
    int remainder = counter - COLUMNS_IN_TAB_STOPS;
    while (remainder > 0) {
	tempstring[i] = ' ';
	--remainder;
	++i;
    }
    tempstring[i++] = '\n';
    tempstring[i] = '\0';

    copy(tempstring, line);
}

/*
  replace_tabs_at_end: overwrites the tabs in line[]
  from pos until COLUMNS_IN_TAB_STOPS with blank chars.
  Creates a char array tempstring with length MAXLINE,
  assumes this will be big enough.
 */
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
  find_last_alphanumeric_char: returns the position
  of the tab, blank or newline char after the last
  alphanumeric character and before the null char,
  or else returns the position of the null char.
 */
int find_last_alphanumeric_char(char line[])
{
    int i;
    int last_pos = -1;
    int state = ALPHA;
    for (i = 0; line[i] != '\0'; ++i) {
	if (line[i] == '\t' || line[i] == ' ' || line[i] == '\n') {
	    state = TAB;
	    last_pos = i;
	}
	else if (state == TAB) {
	    state = ALPHA;
	}
    }
    if (state == ALPHA) last_pos = i; /* set last_pos to null char if the last state was ALPHA,
				       otherwise last_pos will be the last tab or space found */
    return last_pos;
}
