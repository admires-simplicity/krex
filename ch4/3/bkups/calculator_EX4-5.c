/* STATE OF THE PROGRAM........
 * satisfies exes 3 - 5
 * still a bit spaghettish in the getop() function.... */


#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>
#include <string.h>

#define	MAXOP	100	/* max size of operand or operator */
#define	NUMBER	'0'	/* signal that a numebr was found */
#define CMD_NAME	'n'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathfnc(char []);

/*reverse polish calculator*/
int main(void)
{
	int type;
	double op, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) { //s = next operator/operand
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case CMD_NAME:
				mathfnc(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op = pop();
				push(pop() - op);
				break;
			case '/':
				op = pop();
				if (op != 0.0)
					push(pop() / op);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op = pop();
				if (op != 0.0)
					push((int) pop() % (int) op); //i could also use fmod
				else
					printf("error: zero modulator (modulus?)\n");
				break;
			case 'P': case 'p':
				//pop, print, push
				op = pop();
				push(op);
				printf("\t%.8g\n", op);
				break;
			case 'D': case 'd':
				op = pop();
				push(op);
				push(op);
				break;
			case 'S': case 's':
				op = pop();
				op2 = pop();
				push(op);
				push(op2);
				break;
			case 'C': case 'c':
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command \"%s\" type: \"%c\"\n", s, type);
				break;
		}
	}

	return 0;
}

/*mathfnc: check string s for supported math functions*/
void mathfnc(char s[])
{
	double op;

	if (strcmp(s, "sin") == 0) {
		push(sin(pop()));
	} else if (strcmp(s, "cos\0") == 0) {
		push(cos(pop()));
	} else if (strcmp(s, "tan\0") == 0) {
		push(tan(pop()));
	} else if (strcmp(s, "exp\0") == 0) {
		push(exp(pop()));
	} else if (strcmp(s, "log\0") == 0) {
		push(log(pop()));
	} else if (strcmp(s, "pow\0") == 0) {
		op = pop();
		push(pow(pop(), op));
	} else if (strcmp(s, "sqrt\0") == 0) {
		push(sqrt(pop()));
	} else {
		printf("error: multiletter command \"%s\" unknown\n", s);
	}
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/*push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n");
}

/*pop: pop and return top value from stack */
double pop(void)
{
	//printf("%d\n", sp);
	if (sp > 0)
		return val[--sp]; 
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/*clear: clear the stack*/
void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int letter(char c);
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	//note to self: i could refactor this thing into minimethods to make it more concise here....
	int i, c, sign;

	while ((s[0] = c = getch()) == ' ' || c == '\t')	//get char 0 (and skip whitespace)
			;
	s[1] = '\0';

	i = 0;							/* string position */

	//handle letters [if any]
	if (letter(c)) {
		while (letter(s[++i] = c = getch()))		//while next char (which is added to str) is a letter
			;
		s[i] = '\0';
		if (c != EOF)					//one too far
			ungetch(c);		
		if (strlen(s) > 1)				//is cmd
			return CMD_NAME;
		else						//should be singlechar cmd
			return s[0];
	}

	//else, handle symbols [*, /, %...]
	if (!isdigit(c) && c != '.' && c != '-' && c != '+')
		return c;					/* not a number */

	//else, handle signs
	if (c == '-' || c == '+') {				/*handle sign*/
		sign = c;
		if (!isdigit(c = getch()) && c != '.') {	//next char not digit or decimal point
			if (c != EOF)
				ungetch(c); 			//put that thing back where it came from
			return ((sign=='-') ? '-' : '+');
		} else { 					//next char is digit or decimal point
			s[++i] = c;
		}
	}

	//else, handle number
	if (isdigit(c))						/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')						/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

/*letter: returns 0 if not letter, 
 * else returns alphabetical position (1 - 26) for uppercase char, or negative for minus char */
int letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return -(1 + (c - 'a'));
	if (c >= 'A' && c <= 'Z')
		return   1 + (c - 'A');

	return 0;
}


#define	BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free [or unnecessary] position in buf */

int getch(void)	/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
