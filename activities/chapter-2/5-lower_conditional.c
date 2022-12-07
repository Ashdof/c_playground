#include <stdio.h>

int lower(int c);

/**
 * main - convert to lower case
 *
 * Return: void
 */

int main(void)
{
	int c, i;

	while ((c = getchar()) != EOF)
	{
		i = lower(c);
		putchar(i);
	}

	putchar('\n');

	return (0);
}

/**
 * lower - converts to lower case
 * @c: the character
 *
 * Description: this function converts a given character to
 * lower case if its an upper case letter the conditional
 * expression format
 *
 * Return: the lower case letter
 */

int lower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
}
