#include <stdio.h>

int strend(char *s, char *t);

/**
 * main - check for the occurence of a string
 *
 * Description: this programme checks if a given string occurs
 * at the end of another string
 *
 * Return: void
 */

int main(void)
{
	char val1[] = "something";
	char val2[] = "thong";

	printf("%s\n", val1);
	printf("%s\n", val2);
	printf("\n%d\n", strend(val1, val2));

	return (0);
}

/**
 * strend - check for the occurence of a string
 * @s: the first string to be checked
 * @t: the string to check for
 *
 * Description: this function checks for the occurence of the second
 * parameter at the end of the first parameter
 *
 * Return: 1 if true or 0 otherwise
 */

int strend(char *s, char *t)
{
	int i;

	for (; *s != '\0'; s++)
		;

	for (i = 0; *t != '\0'; t++)
		i++;

	while (i > 0)
	{
		if (*--t == *--s)
		{
			--i;
		}
		else
			return (0);
	}

	return (1);
}
