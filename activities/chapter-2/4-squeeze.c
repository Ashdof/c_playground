#include <stdio.h>

#define MAXLINE 1000	/* maximum length of line */

void squeeze(char s1[], char s2[]);
int getlines(char s[], int lim);

/**
 * main - squeeze a string of characters
 *
 * Description: this program invokes the squeee function to delete
 * characters from a given string
 *
 * Return: void
 */

int main(void)
{
	char line1[MAXLINE], line2[MAXLINE];

	getlines(line1, MAXLINE);
	getlines(line2, MAXLINE);

	squeeze(line1, line2);

	printf("%s\n", line1);

	return (0);
}

/**
 * getlines - accept values from the standard input
 * @line: the array of hexadecimal digits
 * @lim: the length of the line
 *
 * Description: this function receives an array of hexadecimal digits
 * from the standard input
 *
 * Return: the length of the line
 */

int getlines(char line[], int lim)
{
	int c, i = 0;

	printf("Value 1: ");

	while (i < lim - 1)
	{
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;
		line[i] = c;
		++i;
	}

	if (c == '\n')
		line[i] = c;

	line[i] = '\0';

	return (i);
}

/**
 * squeeze - delete all characters in s2 from s1
 * @s1: the first array of characters
 * @s2: the second array of characters
 *
 * Description: this function deletes each character in s1 that
 * matches any character in the string s2
 *
 * Return: void
 */

void squeeze(char s1[], char s2[])
{
	int i, j, k;

	i = j = 0;

	while (s1[i] != '\0')
	{
		/* mark characters that appear in both strings */
		for (k = 0; (s1[i] != s2[k]) && s2[k] != '\0'; k++)
		{
			if (s2[k] == ' ')
				continue;
		}
		/* copy unmarked characters in s1 to a new index position */
		if (s2[k] == '\0')
			s1[j++] = s1[i];

		i++;
	}

	s1[j] = '\0';
}
