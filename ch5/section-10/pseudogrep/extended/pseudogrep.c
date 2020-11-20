#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);

//print lines that match pattern from 1st arg
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;


	while (--argc > 0 && (*++argv)[0] == '-')	//precedence:((*(++argv))[0]): 0th character of string pointed to by next argument var
		while (c = *++argv[0]) {		//prec: (*((++(argv[0])))) argv[0] points to current argv. argv points to an array of pointers, so within the current array, ++argv goes to next pointer -> next char (?), and dereferences it, to get that char (?)
			switch(c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("find: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;	
			}
		}
	if (argc != 1)
		printf("Usage: find pattern\n");
	else
		while (get_line(line, MAXLINE) > 0) {
			++lineno;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", line);
				++found;
			}
		}
	return found;
}

/* explanation in The C Book seems to say the same:
 * *++argv is a pointer to the argument string, so (*++argv)[0] is its first character. (an alternate valid form would be **++argv.)
 * Because [] binds tighter than * and ++, the parentheses are necessary; without them the expression would be taken as *++(argv[0]). In fact, that is what we used
 * in the inner loop, where the task is to walk alond a specific argument string. In the inner loop, the expression *++argv[0] increments the pointer argv[0]! */
