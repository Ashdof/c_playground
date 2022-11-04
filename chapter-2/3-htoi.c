#include<stdio.h>

#define MAXLINE 1000	/* maximum length of line */

#define IN 1		/* inside the array of hexadecimal digits */
#define OUT 0		/* outside the array of hexadecimal digits */

int htoi(char s[]);
int getlines(char line[], int maxline);

/**
 * main - convert hexadecimal value to its integer equivalent
 *
 * Description: this program invokes the htoi(S) function which
 * converts a string of hexadecimal digits, including an optional
 * 0x or 0X to its equivalent integer value
 *
 * Return: void
 */

int main(void)
{
	char line[MAXLINE];
	int val;

	getlines(line, MAXLINE);
	val = htoi(line);

	printf("Integer value: %d\n", val);

	return(0);
}

/**
 * getlines - accept values from the standard input
 * @line: the array of hexadecimal digits
 * @maxline: the length of the line
 *
 * Description: this function receives an array of hexadecimal digits
 * from the standard input
 *
 * Return: the length of the line
 */

int getlines(char s[], int lim)
{
	int c, i = 0;

	printf("Hexadecimal value: ");

	while (i < lim - 1)
	{
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;

		s[i] = c;
		++i;
	}

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return (i);
}

/**
 * htoi - converts a hexadecimal value to its integer equivalent
 * @s: an array of hexadecimal values
 *
 * Description: this function converts an array of hexadecimal
 * digit to its integer equivalent
 *
 * Return: the converted integer equivalent
 */

int htoi(char s[])
{
	int hexvalue, i, state, ans;

	i = 0;

	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	ans = 0;
	state = IN;
	while (state == IN)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexvalue = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexvalue = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexvalue = s[i] - 'A' + 10;
		else
			state = OUT;

		if (state == IN)
			ans = 16 * ans + hexvalue;

		++i;
	}


	return (ans);
}
