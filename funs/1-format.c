#include <stdio.h>

#define MAXLINE 1000	/* maximum line size */
#define LASTCHAR '-'	/* last character holder */

int getlines(char line[]);
int format(char src[], char text);

/**
 * main - test the functions
 *
 * Return: void
 */

int main(void)
{
	char text1[MAXLINE];
	char text2 = 'h';

	getlines(text1);

	format(text1, text2);

	printf("\nNew line:\n");
	printf("%s\n", text1);

	return (0);
}

/**
 * getlines - take lines of input from the standard input
 * @line: the array of characters
 *
 * Description: this function accepts inputs from the standard
 * input
 *
 * Return: the string
 */

int getlines(char line[])
{
	int c, i = 0;

	while (i < MAXLINE - 1)
	{
		c = getchar();
		if (c == EOF)
			break;

		line[i] = c;

		i++;
	}

	if (c == '\n')
	{
		line[i] = c;
		i++;
	}

	line[i + 1] = '\0';

	return (i);
}

/**
 * format - format an input string
 * @dest: the destination string
 * @src: the source string
 *
 * Description: this function formats an input string by deleting
 * a specified character from the string as it copies it from
 * 'src' to 'dest'. It then removes a sequence of one or more
 * spaces from the string
 *
 * Return: the formatted string
 */

int format(char src[], char text)
{
	int i, j;
	char lastchar = LASTCHAR;

	i = j = 0;

	while (src[i] != '\0')
	{
		if (src[i] != text)
		{
			if (lastchar != ' ' || src[i] != ' ')
				src[j++] = src[i];

			lastchar = src[i];
		}
		
		i++;
	}

	src[j + 1] = '\0';

	return (j);
}
