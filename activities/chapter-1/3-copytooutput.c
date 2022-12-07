#include <stdio.h>

#define NONBLANK '-'

/**
 * main - copy to output
 *
 * Description: this program copies its input to output, replacing
 * each string of one or more blanks by a single blank
 *
 * Return: void
 */

int main(void)
{
	int c, space, spaces, lastchar;

	lastchar = NONBLANK;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			++space;
			if (lastchar != ' ')
			{
				putchar(c);
				++spaces;
			}
		}
		else
			putchar(c);

		lastchar = c;
	}

	printf("\nTotal spaces entered: %d\n", space);
	printf("Spaces reduced to: %d\n", spaces);

	return (0);
}
