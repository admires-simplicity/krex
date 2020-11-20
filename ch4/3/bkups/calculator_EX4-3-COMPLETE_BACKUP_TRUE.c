#include <stdio.h>
#include <stdlib.h>	/* for atof() */

#define	MAXOP	100	/* max size of operand or operator */
#define	NUMBER	'0'	/* signal that a numebr was found */

int getop(char []);
void push(double);
double pop(void);

/*reverse polish calculator*/
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) { //s = next operator/operand
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					printf("error: zero modulator (modulus?)\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
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

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, sign;

	while ((s[0] = c = getch()) == ' ' || c == '\t')	//get char 0 (and skip whitespace)
			;
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-' && c != '+')
		return c;	/* not a number */

	i = 0;			/* handle number */
	if (c == '-' || c == '+') {			/*handle sign*/
		sign = c;
		if (!isdigit(c = getch()) && c != '.') {//next char not digit or decimal point
			if (c != EOF)
				ungetch(c); //put that thing back where it came from
			return ((sign=='-') ? '-' : '+');
		} else { //next char is digit or decimal point
			s[++i] = c;
		}
	}

	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
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
