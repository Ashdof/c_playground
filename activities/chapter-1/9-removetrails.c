#include <stdio.h>

#define MAXSIZE 100

void trim_trailing(char text[]);

/**
 * main - this program tests for the end of file
 *
 * Return: void
 */

int main(void)
{
	int c, i;
	char msg[MAXSIZE];

	for (i = 0; i < MAXSIZE - 1 && (c = getchar()) != EOF; ++i)
	{
		msg[i] = c;
	}

	printf("Before trimming.\n");
	for (i = 0; i < MAXSIZE - 1; ++i)
	{
		printf("%c", msg[i]);

		if (msg[i] == ' ')
			printf("%c", '_');
	}

	putchar('\n');

	trim_trailing(msg);

	printf("After trimming:\n");
	printf("'%s'\n", msg);

	putchar('\n');

	return (0);
}

/**
 * trim_trailing - trim trailing spaces
 * @text: the array of characters
 *
 * Description: this function takes an array of characters
 * and trims off trailing spaces after the line
 *
 * Return: void
 */

void trim_trailing(char text[])
{
	int index, i;

	index = -1;
	i = 0;

	while (text[i] != '\0')
	{
		if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n')
			index = i;

		++i;
	}

	text[index + 1] = '\0';
}
