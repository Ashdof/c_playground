#include <stdio.h>

#define MAXLINE 1000	/* maximum line length */
#define FOLD 10		/* maximum words to fold */
#define IN 1		/* inside a word */
#define OUT 0		/* outside a word */

int getInput(char input[]);
int foldStream(char input[]);

/**
 * main - fold an input stream
 *
 * Description: this programme folds a string of characters
 *
 * Return: void
 */

int main(void)
{
	char text[MAXLINE];

	getInput(text);
	foldStream(text);

	printf("\n%s\n", text);

	return (0);
}

/**
 * getInput - obtain user input
 * @input: the array of characters
 *
 * Description: this function takes inputs from the standard input
 * and returns it as it is
 *
 * Return: the stream of characters
 */

int getInput(char input[])
{
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; i++)
		input[i] = c;

	if (c == '\n')
	{
		input[i] = c;
		i++;
	}

	input[i] = '\0';

	return (i);
}

/**
 * foldStream - break a long stream into parts
 * @input: the stream of characters
 *
 * Description: this function breaks any stream of characters passed
 * to it via its argument into various parts by an indicated number of
 * words
 *
 * Return: the folded stream of characters
 */

int foldStream(char input[])
{
	int i, j, state, words;

	i = j = words = 0;
	state = OUT;

	while (input[i] != '\0')
	{
		input[j++] = input[i];

		if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
		{
			state = OUT;

			if (words == FOLD)
			{
				input[i] = '\n';
				words = 0;
			}
		}
		else if (state == OUT)
		{
			state = IN;
			words++;
		}

		i++;
	}

	input[j] = '\0';

	return (j);
}
