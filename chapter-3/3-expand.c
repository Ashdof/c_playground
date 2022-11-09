#include <stdio.h>

#define MAXLINE 1000	/* maximum line length */

int getlines(char line[]);
int expand(char dest[], char src[]);
/**
 * main - expand an array of characters
 *
 * Description: this program exapnds an array of characters
 * by filling in the missing characters
 *
 * Return: void
 */

int main(void)
{
	char text1[MAXLINE], text2[MAXLINE];

	getlines(text2);

	expand(text1, text2);

	printf("Complete list:\n");
	printf("%s", text1);

	return (0);
}

/**
 * getlines - collect array of characters from the standard
 * input
 * @line: the string of characters
 *
 * Description: this function takes strings of characters from
 * the standard input
 *
 * Return: the string of characters
 */

int getlines(char line[])
{
	int c, i = 0;

	while (i < MAXLINE - 1)
	{
		c = getchar();
		
		if (c == '\n' || c == EOF)
			break;

		line[i] = c;

		i++;
	}

	if (c == '\n')
	{
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return (i);
}

/**
 * expand - expand a given string
 * @dest: the destination string
 * @src: the source string
 *
 * Description: this function expands shorthand notation like a-z
 * in a given string into the equivalent complete list of abc...xyz
 * as it compies values from the src to dest.
 *
 * Return: the complete list
 */

int expand(char dest[], char src[])
{
	int i, j, temp;

	i = j = 0;

	while ((temp = src[i++]) != '\0')
	{
		if (src[i] == '-' && src[i + 1] >= temp)
		{
			i++;	/* skip the character */

			while (temp < src[i])
				dest[j++] = temp++;
		}
		else
			dest[j++] = temp;
	}

	dest[j] = '\0';

	return (j);
}
