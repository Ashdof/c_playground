#include <stdio.h>

#define LIM 100		/* maximum line length */

/**
 * main - smart loop
 *
 * Description: this program uses a while loop to execute the same
 * action as this for loop.
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c!=EOF; ++i)
 *
 * Return: void
 */

int main(void)
{
	int c, i;
	char s[LIM];

	i = 0;
	while (i < LIM - 1)
	{
		c = getchar();

		if (c == '\n')
			break;

		if (c == EOF)
			break;

		s[i] = c;

		++i;
	}

	/* print values in the array */
	printf("%s\n", s);

	return (0);
}
