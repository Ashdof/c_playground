#include <stdio.h>

/**
 * main - replace escape sequences
 *
 * Description: this program copies its input to its output, replacing
 * each tab by '\t', each backspace by '\b' and each backslash by '\\'
 *
 * Return: void
 */

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\')
		{
			putchar('\\');
		}
		else
		{
			putchar(c);
		}
	}

	return (0);
}
