#include <stdio.h>

#define WORD  1
#define BLANK 0
#define MAXLINE 1000
#define SPLIT 20

#define SPACES_IN_TABS 4
#define ALPHA 0
#define TAB   1


int PMS_getline(char line[], int max_len);
void copy(char from[], char to[]);
int find_last_alphanumeric_char(char line[], int pos);
void insert_char_at_index(char line[], char insert_char, int index);
void fold_line(char line[], int position);


int main()
{

    char line[MAXLINE];
    int len = 0;
    int sp = 0;
    int split_multiplier = 0;
    int counter;
    while ((len = PMS_getline(line, MAXLINE)) > 0) { // while there's input
	if (len > SPLIT) {
	    counter = 1;
	    split_multiplier = len / SPLIT;
	    //printf("%d\n", split_multiplier); //for debugging
	    while (counter <= split_multiplier) {
		sp = find_last_alphanumeric_char(line, SPLIT * counter);
		fold_line(line, sp);
		counter++;
	    }
	}
	printf("%d- %s", len, line);
    }
    return 0;
}


/*
  PMS_getline: gets a line of text from input, stores in line[];
  returns the int length of line[]
*/
int PMS_getline(char line[], int max_len)
{

    int i, c;
    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	line[i] = c;
    }
    if (c == '\n') {
	line[i++] = c;
    }

    line[i] = '\0';
    return i;
    
}

/*
  find_last_alphanumeric_char: returns the position
  of the first tab or blank char that occurs after the last
  non-blank character before pos;
  if no blanks are found, returns the position of the char at pos-1,
  so e.g. the 20th char of a string will be indexed by line[19]
*/
int find_last_alphanumeric_char(char line[], int pos)
{

    int index;
    int spaces = 0;
    for (index = 0; index < pos; ++index) {
	if (line[index] == ' ' || line[index] == '\t') {
	    ++spaces;
	}
	else spaces = 0;
    }
    if (spaces > 0) {
	index = index - spaces;
    }
    return index;
    
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
  fold_line: splits line[] at position, either with newline
  if line[position] is a blank, or hyphen-newline if line[position]
  is non-blank char
*/
void fold_line(char line[], int position)
{
    /* tempstring might have to be split entirely with hyphen-newlines
     so it needs to be big enough to store the potential hyphens */
    char tempstring[MAXLINE + (MAXLINE / SPLIT)]; // this is way too big
    
    int i, j;

    for (i = 0, j = 0; i < position; ++i) { /* copy line into tempstring until line[position] */
	tempstring[i] = line[i];
    }
    if (line[position] == ' ' || line[position] == '\t') { /* insert newline if line[position] is a blank char */
	//printf("blank found: line[position] = %c\n", line[position]);
	insert_char_at_index(tempstring, '\n', position);
        /* increment j and i to the next char */
	j = position + 1;
	i = position + 1;
    }
    else { 			/* line[position] is non-blank, insert hyphen then newline */
	//printf("non-blank found: line[position] = %c\n", line[position]);
	insert_char_at_index(tempstring, '-', position++);
	insert_char_at_index(tempstring, '\n', position);
	j = position + 1; // only j incremented because line[position] now refers to next char
    }

    for ( ; line[i] != '\0'; ++i, ++j) { /* copy the rest of line into tempstring */
	tempstring[j] = line[i];
    }
    //printf("null char? %d\n", line[i]);
    tempstring[j] = line[i];	/* copy null char to end of tempstring */
    //printf("DEBUG: tempstring = %s\n", tempstring);
    copy(tempstring, line);	/* copy tempstring to line, essentially swapping them */

}

void insert_char_at_index(char line[], char insert_char, int index) {

    line[index] = insert_char;
}

