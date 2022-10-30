#include <stdio.h>

/**
 * main - print one word per line
 *
 * Description: this program prints its input, one word per
 * line
 *
 * Return: void
 */

int main(void)
{
	/* initialise a variable to recieve inputs */
	int c;

	/* while there is another line */
	while ((c = getchar()) != EOF)
	{
		/* print the character recevied */
		putchar(c);

		/* the input is a space */
		if (c == ' ')
			putchar('\n');
	}

	return (0);
}
