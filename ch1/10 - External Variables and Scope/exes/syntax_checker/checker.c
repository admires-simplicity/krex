/* Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets, and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) */
/* I'm only going to do checks for unbalanced parentheses, brackets, braces, because I think that's all the answer does too */

main()
{
	int c;
	int n_paren, n_bracket, n_brace;

	while ((c = getchar) != EOF) {
		if (c == '(') ++n_paren;
		else if (c == ')') --n_paren;
		else if (c == '[') ++n_bracket;
		else if (c == ']') --n_bracket;
		else if (c == '{') ++n_brace;
		else if (c == '}') --n brace;	
	}

	printf("Program has %d wrong parentheses, %d wrong brackets, and %d wrong braces");
}

/* i got this far and decided I didn't want to do this, and I'm skipping it. I looked at the answer also. */
