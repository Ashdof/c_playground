#include <stdio.h>

#define MAXLINE 1000	/* maximum length of line */

int getlines(char line[]);
int escape(char dest[], char src[]);

/**
 * main - implement sequence replacement
 *
 * Description: this program replaces escape sequences
 * with their corresponding characters
 *
 * Return: void
 */

int main(void)
{
	char text1[MAXLINE], text2[MAXLINE];

	getlines(text2);

	escape(text1, text2);

	printf("\nNew line:\n");
	printf("%s\n", text1);

	return (0);

}

/**
 * getlines - takes lines of inputs from the user
 * @line: the array of characters
 *
 * Description: this function takes inputs of characters
 * from the standard input and returns it as a string
 *
 * Return: the array of characters
 */

int getlines(char line[])
{
	int c, i = 0;

	for (; i < MAXLINE - 1 && (c = getchar()) != EOF; i++)
	{
		line[i] = c;
	}

	line[i] = '\0';

	return (i);
}

/**
 * escape - replace escape sequences with visible characters
 * @dest: the destination string
 * @src: the source string
 *
 * Description: this function converts characters like newline and
 * tabs into visible escape sequences line '\n' and '\t' as it copies
 * string src to dest.
 *
 * Return: the new string
 */

int escape(char dest[], char src[])
{
	int i, j;

	i = j = 0;
	while (src[i] != '\0')
	{
		switch (src[i])
		{
			case '\t':
				dest[j] = '\\';
				++j;
				dest[j] = 't';
				break;
			case '\n':
				dest[j] = '\\';
				++j;
				dest[j] = 'n';
				break;
			case '\a':
				dest[j] = '\\';
				++j;
				dest[j] = 'a';
				break;
			case '\b':
				dest[j] = '\\';
				++j;
				dest[j] = 'a';
				break;
			case '\r':
				dest[j] = '\\';
				++j;
				dest[j] = 'r';
				break;
			case '\v':
				dest[j] = '\\';
				++j;
				dest[j] = 'v';
				break;
			case '\\':
				dest[j] = '\\';
				++j;
				dest[j] = '\\';
				break;
			case '\?':
				dest[j] = '\\';
				++j;
				dest[j] = '?';
				break;
			case '\"':
				dest[j] = '\\';
				++j;
				dest[j] = '"';
				break;
			default:
				dest[j] = src[i];
		}
		++i;
		++j;
	}

	dest[i] = '\0';

	return (i);
}
