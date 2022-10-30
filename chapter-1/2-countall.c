#include <stdio.h>

/**
 * main - counts for newlines, blanks and tabs
 *
 * Description: this program counts for the number of newlines,
 * blanks and tabs present in an input
 *
 * Return: void
 */

int main(void)
{
	int c, newlines, blanks, tabs;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++blanks;
		else if (c == '\t')
			++tabs;
		else if (c == '\n')
			++newlines;
	}

	printf("\nSummary\n");
	printf("Blanks: %d\n", blanks);
	printf("Tabs: %d\n", tabs);
	printf("Lines: %d\n", newlines);

	return (0);
}
