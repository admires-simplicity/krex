#include <stdio.h>

#define	TABW	8
#define	MAXLINE	80
#define MAXWORD	1000

int c;			/* char from getchar */

int handle_tab(int position);
int get_word(int char_init, char word[]);
void put_spaces(int n_of_spaces);
int handle_long_word(char word[], int position, int n_of_spaces);
		
/* Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column. */

/* 1. \n after the last nonblank char before the n-th column -> after last word before cutoff point
 * 2. Handle very long lines
 * 3. Handle no blanks / tabs before cutoff */

/* A QUESTION: Once handle_long_word(...) is written, how will the program handle words longer than MAXWORD? 
 * ANSWER THAT I JUST THOUGHT OF: well, what I did was I just saved all the characters up to MAXWORD-1, and didn't save the 'arbitrarily long length' */

main()
{
	extern int c;
       	int ns = 0; /*number spaces*/
	int lw = 0; /*length word*/
	int pos = 0; /*o position*/

	char w[MAXWORD]; 

	c = getchar();
	while (c != EOF) {
		if (c == '\t') {
			pos = handle_tab(pos); 	/*'\t'*/
			c = getchar();
		} else if (c == ' ') {
			++ns;		/*' '*/
			c = getchar();
		} else if (c == '\n') {			/*'\n'*/
			putchar(c);
			pos = 0;
			c = getchar();
		} else {					
			if ((pos + ns + (lw = get_word(c, w))) <= MAXLINE) { 	/*room for spaces and word, on this line*/
				put_spaces(ns);	/*put spaces*/
				printf(w);	/*put word*/
				pos = pos + ns + lw;
			} else if (lw <= MAXLINE) {				/*word can fit on a line*/
				putchar('\n');
				printf(w);	/*put word on next line*/ 
				pos = lw;
			} else {						/*word is too long, and must be broken over a line*/
				pos = handle_long_word(w, pos, ns);
			}	
			ns = 0; /* restart number of spaces counter, because word has already been printed with spaces before it,
				   or spaces have been skipped and word has been printed without them. */
			/* get_word stops when it encounters a nonword char, so it needs access to c and writes to c, therefor,
			 * we shouldn't do getchar() after get_word() */
		}
	}
}

/* Write a word to the string */
int get_word(int letter_initial, char string[])
{
	extern int c;
	int i = 1;

	string[0] = letter_initial;
	while (((c = getchar()) != EOF) && c != ' ' && c != '\t' && c != '\n') {
		if (i < MAXWORD-1) {
			string[i] = c;
			++i;
		}
	}
	string[i] = '\0';
	/* extern int c is now equal to EOF, ' ', '\t', or '\n'. */
	return i;
}

int handle_tab(int position)
{
	int ns = TABW - position % TABW;
	if (position + ns <= MAXLINE) {
		put_spaces(ns);
		return position + ns;
	} else {
		put_spaces(MAXLINE - position);
		putchar('\n');
		return 1;
	}
}

void put_spaces(int ns)
{
	for (int i = 0; i < ns; ++i)
		putchar(' ');
}

int handle_long_word(char w[], int pos, int ns)
{
	int i = 0;

	/* printf("THIS SHOULDN'T EVER REALLY BE HIT, SO I WILL WRITE IT LATER I GUESS, BECAUSE I WANT THE MAIN BIT TO WORK, MAINLY"); */
	if ((ns + 1) <= MAXLINE) { /* room for spaces before first char of word, on current line */
		put_spaces(ns);
		pos = pos + ns;
	} else {
		putchar('\n');
		pos = 0;
	}

	while (w[i] != '\0') {
		if (pos < MAXLINE) {
			putchar(w[i]);
			++pos;
		} else {
			putchar('\n');
			putchar(w[i]);
			pos = 1;
		}
		++i;
	}
	return pos;
	//n % MAXLINE   //lw % MAXLINE ???
}

/* post hoc, memorandum, redundant as that is
 * I think my original intent of the handle_tab function wasn't to replace tabs with spaces, but to calculate the proper position in the line displaced by the tabs... whatever I guess. */
