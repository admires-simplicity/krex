//Write a cross-referencer that prints a list of all the words in a document, and, for each word, a list of the line numbers on which it occurs. Remove noise words like "the", "and", and so on.
#include <ctype.h>	//isalpha
#include <stdio.h>	//printf
#include <stdlib.h>	//malloc
#include <string.h>	//strcmp

#define MAXWORD 100

char *noise[] = {
	"the", "of", "and", "to", "a", "in", "that", "is", "it", "with", "for" };

//DYNAMICALLY ALLOCATED INTEGER ARRAY 5HEAD GALAXY BRAIN CODING WARLORD STUFF!!!
typedef struct list {
	int *values;
	int max_index;
} list;

struct tnode {
	char *word;
	list lines;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void lower(char *);

int line_number = 1;

int main(void)
{
	struct tnode *root;
	char word[MAXWORD];


	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) {	
			lower(word);	//convert word to all lowercase
			//if not noise(word), add word
			root = addtree(root, word);	//handle word on tree
		}
	////////WHAT I HAVE TO DO NEXT IS WRITE THIS METHOD???
	////////WHAT I HAVE TO DO NEXT IS WRITE THIS METHOD???
	////////WHAT I HAVE TO DO NEXT IS WRITE THIS METHOD???
	////////WHAT I HAVE TO DO NEXT IS WRITE THIS METHOD???
	treeprint(root);
	
	return 0;
}

//convert string to lowercase
void lower(char *s)
{
	while (*s != '\0') {
		if (*s >= 'A' && *s <= 'Z')
			*s = *s - 'A' + 'a';
		++s;
	}
}

struct tnode *talloc(void);
char *my_strdup(char *);
int list_append(list, int);
//int *valloc(list, int);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) { 	/* new word */
		p = talloc();	/*make a new node*/
		(*p).word = my_strdup(w);

		p->lines.max_index = -1; //so first append goes to pos 0
		list_append(p->lines, line_number);

		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) { //repeated word
		if (*(p->lines.values+p->lines.max_index) < line_number) //if new line
			list_append(p->lines, line_number); //append line
	} else if (cond < 0)	//less than into left subtree
		p->left = addtree(p->left, w);
	else			//greater than into right subtree
		p->right = addtree(p->right, w);
	return p;
}

//Append int to int list, error checked
//returns 0 if malloc fails
int list_append(list l, int x)
{
	int *p = l.values;

	++l.max_index;	
	if ((l.values = malloc(sizeof (int) * (l.max_index))) == NULL) {
		l.values = p;
		--l.max_index;
		return -1; //fail
	}

	*(l.values + (l.max_index)) = line_number;
	
	return l.max_index;
}

#include <string.h>

//make a node
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode)); //pointer to somewhere I can safely put this tnode
}

char *my_strdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);	//somewhere I can put a string of this max_indexgth, +1 for '\0'
	if (p != NULL)
		strcpy(p, s); //copy the passed string to where this pointer refers to
	return p; //return pointer
}

////allocate space for list, given the list, and current line number
//int *valloc(list l, int n)
//{
//	int *p;
//
//	if (l.max_index == 0)
//		p = (int *) malloc(sizeof n);
//	else
//		p = (int *) malloc(sizeof l.max_index * (max_index + 1));
//
//	return p;
//}



/*getword: get next word or character from input*/
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		if (c == '\n')
			++line_number;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; ++w)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
			}
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];	/*buffer for ungetch*/
int bufp = 0;		/*next free position in buf*/

int getch(void)		/*get a (possibly pushed back) character*/
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/*push character back on input*/
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
