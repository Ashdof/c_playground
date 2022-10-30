#include <stdio.h>
#define MAXSIZE 1000	/* maximum length of line */

/* int getlen(char text[]); */
void reverses(char text[], int n);

/**
 * main - reverses a line of text
 *
 * Description: this program reverses its input, one line at a time.
 * The 'i' in counts for the length of the string input or the number
 * of character input, including spaces and tabs.
 *
 * Return: void
 */

int main(void)
{
	int c, i;
	char s[MAXSIZE];

	for (i = 0; i < MAXSIZE - 1 && (c = getchar()) != EOF; ++i)
	{
		s[i] = c;
	}

	reverses(s, i);

	printf("%s\n", s);
	printf("String length: %d\n", i);

	return (0);
}

/**
 * getlen - length of a string
 * @text: the array of characters to determine its length
 *
 * Description: this function takes an array of characters as input
 * and returns its length. This function is currently not in use because
 * the main function relies on the 'i' used in the for loop to obtain the
 * input from the standard input. This 'i' variable counts for the number
 * of character input, including spaces and tabs
 *
 * Return: length of the string
 */

int getlen(char text[])
{
	int i = 0;

	while (text[i] != '\0')
		++i;

	return (i);
}

/**
 * reverses - reverse an array of characters
 * @text: the array of characters
 * @n: the length of the string
 *
 * Return: void
 */

void reverses(char text[], int n)
{
	int i, temp;

	for (i = 0; i < n / 2; ++i)
	{
		temp = text[i];
		text[i] = text[n - i - 1];
		text[n - i - 1] = temp;
	}
}
