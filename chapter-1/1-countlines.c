#include <stdio.h>

/**
 * main - counts lines
 *
 * Description: this program counts the number of line entries made
 * through the standard input using getchar. The newline character,
 * '\n' marks the end of a line and counting lines basically means
 * counting the newline character.
 *
 * Return: void
 */

int main(void)
{
	/* intialise variables to recieve input from the keyboard and for counting */
	int c, i;

	i = 0;

	/* while there is another line */
	while ((c = getchar()) != EOF)
	{
		/* if an input is a newline character */
		if (c == '\n')
			/* increment value in 'i' */
			++i;
	}

	/* print the result on the screen */
	printf("Line count: %d\n", i);

	return (0);
}
