#include <stdio.h>

#define MAXLINE 1000    /* maximum line input */

int get_line(char s[], int lim);
void copy(char d[], char s[]);

/**
 * main - print longest line
 *
 * Description: this function prints the lines with character
 * count more than 80. In the event of less than 80 characters,
 * a message informs the user of the expected number of characters
 *
 * Return: void
 */

int main(void)
{
	int len;        /* the current line length */
	int max;        /* maximum length seen so far */
	char line[MAXLINE];     /* current line input */
	char longest[MAXLINE];  /* longest line saved here */

	max = 0;

	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max < 80)            /* there was a line */
	{
		printf("\nLongest line must have at least 80 characters\n");
	}
	else
	{
		printf("\nLength of longest line: %d\n", max);
		printf("%s", longest);
	}

	putchar('\n');

	return (0);
}

/**
 * get_line - reads a line and return its length
 * @s: an array for receiving the lines
 * @lim: the maximum line input
 *
 * Description: This function reads a line and returns
 * the number of characters that make up the line
 *
 * Return: the length of the line
 */

int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return (i);
}

/**
 * copy - copies a line
 * @src: the source string
 * @dest: the destination
 *
 * Description: this function copies characters from
 * the source string to the dest array
 *
 * Return: void
 */

void copy(char dest[], char src[])
{
	int i = 0;

	while ((dest[i] = src[i]) != '\0')
		++i;
}
