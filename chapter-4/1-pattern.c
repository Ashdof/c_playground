#include <stdio.h>

#define MAXLINE 1000				/* maximum line length */

int strrindex(char src[], char searchfor[]);	/* search for the rightmost occurrence of the pattern */

/**
 * main - return the index of a pattern
 *
 * Description: this program searches for a pattern from the end
 * of a string and prints the index at which the pattern is first
 * seen
 *
 * Return: void
 */

int main(void)
{
	char line[] = "I would love to see you.";
	int found = 0;

	char pattern[] = "ould";	/* pattern word to search for */
	found = strrindex(line, pattern);
	printf("Found at: %d\n", found);

	return (0);
}

/**
 * strindex - get the rightmost index of a pattern
 * @src: the source string
 * @searchfor: the pattern to search for
 *
 * Description: this function searches for a pattern from the
 * rightmost end of the string
 *
 * Return: the index where the pattern is found in the line
 * or -1 if none
 */

int strrindex(char src[], char searchfor[])
{
	int i, j, k, r;
       
	r = -1;
	i = 0;	

	while (src[i] != '\0')
	{
		for (j = i, k = 0; searchfor[k] != '\0' && src[j] == searchfor[k]; j++, k++)
			;

		if (k > 0 && searchfor[k] != '\0')
			r = i;

		i++;
	}

	return (r);
}

