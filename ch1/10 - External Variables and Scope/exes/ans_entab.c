#include <stdio.h>

#define TABINC	8	/* TAB INCREMENT SIZE */

/* replace tabs with the proper number of blanks */
main()
{
	int c, nb, nt, pos;

	nb = 0;		/* number of blanks necessary */
	nt = 0;		/* n tabs necessary */
	for (pos = 1; (c = getchar()) != EOF; ++pos) {
		if (c == ' ') {
			if (pos % TABINC != 0)
				++nb;		/*increment n of blanks*/
			else {
				nb = 0;		/*reset n of blanks*/
				++nt;		/*one more tab*/
			}
		} else {
			for ( ; nt > 0; --nt)
				putchar('\t');	/*output tabs*/
			if (c == '\t')		/*forget the blanks*/
				nb = 0;
			else
				for ( ; nb > 0; --nb)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				pos = pos + (TABINC - (pos-1) % TABINC) - 1;
		}
	}
}
